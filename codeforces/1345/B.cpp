#include <bits/stdc++.h>

using namespace std;
long long t,n;
inline long long f(long long x)
{
    return 3*x*x+x;
}
int ans(long long n)
{
    if(n<4)
        return 0;

    long long st=1;
    long long dr=sqrt(n);
    long long mij, last=1;

    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(f(mij)<=n)
        {
            last=mij;
            st=mij+1;
        }
        else
        {
            dr=mij-1;
        }
    }

    return 1+ans(n-f(last));
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        cout<<ans(2*n)<<'\n';
    }
    return 0;
}
