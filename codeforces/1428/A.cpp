#include <bits/stdc++.h>

using namespace std;
long long t,x,x2,y,y2;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>x>>y>>x2>>y2;

        if(x==x2)
            cout<<abs(y-y2)<<'\n';
        else if(y==y2)
            cout<<abs(x-x2)<<'\n';
        else
            cout<<abs(x-x2)+abs(y-y2)+2<<'\n';
    }
    return 0;
}
