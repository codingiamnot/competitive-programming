#include <bits/stdc++.h>

using namespace std;
long long t,l,r,x;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>l>>r;
        if(2*l>=r+1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
