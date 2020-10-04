#include <bits/stdc++.h>

using namespace std;
long long t,a,b,c;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b>>c;
        cout<<max(a, max(b, c))<<'\n';
    }
    return 0;
}
