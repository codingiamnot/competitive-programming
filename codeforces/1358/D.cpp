#include <iostream>

using namespace std;
int n,i,st,dr,mij,last;
long long ans,nans,x,t;
long long zile[400005];
long long val[400005];
long long a[400005];
long long gauss(long long x)
{
    if(x<=0)
        return 0;
    return x*(x+1)/2;
}
int main()
{
    cin>>n>>x;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        a[n+i]=a[i];
    }
    n*=2;

    for(i=1;i<=n;i++)
    {
        zile[i]=zile[i-1]+a[i];
        val[i]=val[i-1]+gauss(a[i]);
    }

    for(i=1;i<=n;i++)
    {
        st=1;
        dr=i+1;
        last=i+1;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            if(zile[i]-zile[mij-1]<=x)
            {
                last=mij;
                dr=mij-1;
            }
            else
                st=mij+1;
        }

        t=x-zile[i]+zile[last-1];
        nans=val[i]-val[last-1]+gauss(a[last-1])-gauss(a[last-1]-t);
        ans=max(ans, nans);
    }

    cout<<ans;
    return 0;
}
