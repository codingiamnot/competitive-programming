#include <iostream>

using namespace std;

bool ok;
long long t,n,i,add;
long long a[200005];
long long dpl[200005];
long long dpr[200005];

bool check(long long a, long long b, long long c, long long d)
{
    if(a==-1 || b==-1 || c==-1 || d==-1)
        return false;

    if(a>b)
        return false;
    b-=a;

    if(b>c)
        return false;
    c-=b;

    if(c>d)
        return false;
    d-=c;

    if(d)
        return false;

    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        ok=false;

        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];

        dpl[0]=0;
        dpr[n+1]=0;

        for(i=1;i<=n;i++)
        {
            dpl[i]=a[i]-dpl[i-1];
            if(dpl[i]<0 || dpl[i-1]<0)
                dpl[i]=-1;
        }

        for(i=n;i>=1;i--)
        {
            dpr[i]=a[i]-dpr[i+1];
            if(dpr[i]<0 || dpr[i+1]<0)
                dpr[i]=-1;
        }

        if(dpl[n]==0)
            ok=true;

        for(i=1;i<n;i++)
            if(check(dpl[i-1], a[i+1], a[i], dpr[i+2]))
                ok=true;

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
