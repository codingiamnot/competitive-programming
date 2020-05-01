#include <bits/stdc++.h>

using namespace std;
long long t,a,b,n,i;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        a=0;
        b=0;
        for(i=1;i<=n/2-1;i++)
            a+=1<<i;
        for(i=n/2;i<n;i++)
            b+=1<<i;
        a+=1<<n;
        cout<<a-b<<'\n';
    }
    return 0;
}
