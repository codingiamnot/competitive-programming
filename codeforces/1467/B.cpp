#include <iostream>

using namespace std;

int t,n,i,nr,ans;
int a[300005];
bool ok[300005];

bool verif(int i)
{
    if(i==1 || i==n)
        return false;
    
    if(a[i]>a[i-1] && a[i]>a[i+1])
        return true;
    if(a[i]<a[i-1] && a[i]<a[i+1])
        return true;

    return false;
}
int ch(int i, int x)
{
    int last=a[i];
    a[i]=x;

    int ans = ok[i-1]+ok[i]+ok[i+1]-verif(i-1)-verif(i)-verif(i+1);

    a[i]=last;

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
            ok[i]=false;

        nr=0;
        for(i=2;i<n;i++)
            if(verif(i))
            {
                nr++;
                ok[i]=true;
            }

        ans=nr;
        for(i=2;i<n;i++)
        {
            ans=min(ans, nr-ch(i, a[i-1]));
            ans=min(ans, nr-ch(i, a[i+1]));
        }

        cout<<ans<<'\n';
    }
    return 0;
}
