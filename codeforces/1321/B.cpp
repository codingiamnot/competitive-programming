#include <bits/stdc++.h>

using namespace std;
long long n,i,maxi,x;
map <long long, long long> m;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        m[i-x]+=x;
    }
    for(auto it : m)
    {
        maxi=max(maxi, it.second);
    }
    cout<<maxi;
    return 0;
}
