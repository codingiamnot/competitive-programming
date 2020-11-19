#include <bits/stdc++.h>

using namespace std;
long long t,x,y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t)
    {
        t--;
        cin>>x>>y;
        cout<<2*min(x, y) + max((long long)0, 2*abs(x-y)-1)<<'\n';
    }
    return 0;
}
