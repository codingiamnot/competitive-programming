#include <bits/stdc++.h>

using namespace std;
map <long long, long long> m;
long long n,i,maxi,nrmax;
struct poz
{
    long long val, nr;
} a[200005];
long long calc(long long nr)
{
    long long ans=0;
    while(nr)
    {
        if(nr%2)
            break;
        ans++;
        nr/=2;
    }
    return ans;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i].val;

    for(i=1;i<=n;i++)
    {
        a[i].nr=calc(a[i].val);
        m[a[i].nr]++;
    }

    for(auto it : m)
    {
        if(it.second>maxi)
        {
            maxi=it.second;
            nrmax=it.first;
        }
    }

    cout<<n-maxi<<'\n';
    for(i=1;i<=n;i++)
    {
        if(a[i].nr!=nrmax)
            cout<<a[i].val<<' ';
    }
    return 0;
}
