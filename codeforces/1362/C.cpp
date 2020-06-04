#include <bits/stdc++.h>

using namespace std;
long long n,t,ans;
void f(long long n, long long i)
{
    if(!n)
        return;
    ans+=((n+1)/2)*i;
    n/=2;
    i++;
    f(n, i);
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ans=0;
        f(n, 1);
        cout<<ans<<'\n';
    }
    return 0;
}
