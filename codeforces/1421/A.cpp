#include <bits/stdc++.h>

using namespace std;
long long t,a,b;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b;
        cout<<min(a^b, b^a)<<'\n';
    }
    return 0;
}
