#include <bits/stdc++.h>

using namespace std;

long long k,l,r,t,x,y,nr;
map<int, int> m;
int main()
{
    cin>>k>>l>>r>>t>>x>>y;

    if(y<=x)
    {
        if(k+y>r)
            k-=y;

        if(k<l)
        {
            cout<<"No";
            return 0;
        }

        if(x==y)
        {
            cout<<"Yes";
            return 0;
        }

        long long nr=(k-l)/(x-y);
        if(t>nr)
            cout<<"No";
        else
            cout<<"Yes";

        return 0;
    }

    while(true)
    {
        nr=(k-l)/x;

        if(t<=nr)
        {
            cout<<"Yes";
            return 0;
        }
        t-=nr;

        k-=x*nr;

        k+=y;
        if(k>r)
        {
            cout<<"No";
            return 0;
        }

        if(m.find(k%x)!=m.end())
        {
            cout<<"Yes";
            return 0;
        }
        m[k%x]=1;
    }
    return 0;
}
