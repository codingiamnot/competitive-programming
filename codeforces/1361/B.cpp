#include <bits/stdc++.h>
#define mod 1000000007
#define Nmax 1000005

using namespace std;
long long put(long long baza, long long exp)
{
    if(!exp)
        return 1;

    long long ans=put(baza, exp/2);

    ans*=ans;
    ans%=mod;

    if(exp%2)
        return (ans*baza)%mod;
    else
        return ans;
}
long long calc(long long x, long long p, long long y)
{
    if(p == 1) {
        return x;
    }
    long long ans = 1;
    for(long long i = 1; i <= y; i++) {
        if(ans * p > Nmax) {
            return -1;
        }
        ans *= p;
    }
    if(x * ans > Nmax) {
        return -1;
    }
    return x * ans;
}
long long t,n,p,need,new_need,x,dif,i,j,nr;
long long a[1000005];
long long fr[1000005];
bool ok;
vector <long long> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t)
    {
        t--;
        v.clear();
        dif=0;
        cin>>n>>p;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            fr[a[i]]++;
        }
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        int new_n = 1;
        for(int i = 2; i <= n; i++) {
            if(a[i] != a[i - 1]) {
                a[++new_n] = a[i];
            }
        }
        n = new_n;

        for(i=1;i<=n;i++)
        {
            if(fr[a[i]]%2==0)
                continue;

            x=a[i];
            need=1;
            ok=false;

            for(j=i+1;j<=n;j++)
            {
                new_need=calc(need, p, x-a[j]);
                if(new_need==-1)
                    break;

                if(new_need<=fr[a[j]])
                {
                    ok=true;
                    fr[a[j]]-=new_need;
                    i=j-1;
                    break;
                }
                else
                {
                    need=new_need-fr[a[j]];
                    x=a[j];
                }
            }

            if(!ok)
            {
                dif=put(p, a[i]);
                for(j=i+1;j<=n;j++)
                {
                    dif-=(fr[a[j]]*put(p, a[j]))%mod;
                    if(dif<0)
                        dif+=mod;
                }
                break;
            }
        }

        cout<<dif<<'\n';

        for(i=1;i<=n;i++)
            fr[a[i]]=0;
    }
    return 0;
}