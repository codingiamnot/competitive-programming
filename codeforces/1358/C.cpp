#include <bits/stdc++.h>

using namespace std;
long long t,x,y,x2,y2;
inline long long sum(long long x)
{
    return x*(x+1)/2;
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>x>>y>>x2>>y2;
        x=x2-x;
        y=y2-y;
        cout<<sum(x+y)-sum(x)-sum(y)+1<<'\n';
    }
    return 0;
}
