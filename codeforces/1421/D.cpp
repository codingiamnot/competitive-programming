#include <bits/stdc++.h>

using namespace std;
long long solve(long long x, long long y, long long a, long long b, long long c)
{
    long long nr=min(x, y);
    long long ans=nr*a+(x-nr)*b+(y-nr)*c;
    ans=min(ans, x*b+y*c);
    return ans;
}
long long solve2(long long x, long long y, long long a, long long b)
{
    return x*a+y*b;
}
long long t,x,y,c1,c2,c3,c4,c5,c6,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>x>>y;
        cin>>c1>>c2>>c3>>c4>>c5>>c6;

        c1=min(c1, c2+c6);
        c2=min(c2, c1+c3);
        c3=min(c3, c2+c4);
        c4=min(c4, c3+c5);
        c5=min(c5, c4+c6);
        c6=min(c6, c1+c5);

        if(x>=0 && y>=0)
            ans=solve(x, y, c1, c6, c2);
        if(x<0 && y>=0)
            ans=solve2(-x, y, c3, c2);
        if(x>=0 && y<0)
            ans=solve2(x, -y, c6, c5);
        if(x<0 && y<0)
            ans=solve(-x, -y, c4, c3, c5);

        cout<<ans<<'\n';
    }
    return 0;
}
