#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
struct seg
{
    long long l,r;
    seg(long long l, long long r)
    {
        this->l=l;
        this->r=r;
    }
    bool operator<(seg b) const
    {
        if(l!=b.l)
            return l<b.l;
        return r<b.r;
    }
};
struct tel
{
    long long l, r;
    tel(long long l, long long r)
    {
        this->l=l;
        this->r=r;
    }
    bool operator<(tel b) const
    {
        return r<b.r;
    }
};
int n,i;
long long x,y,ans,l,r;
vector <seg> v;
multiset <tel> s;
int main()
{
    cin>>n>>x>>y;
    for(i=1;i<=n;i++)
    {
        cin>>l>>r;
        v.push_back(seg(l, r));
    }

    sort(v.begin(), v.end());

    /*
    cout<<'\n';
    for(auto it : v)
    {
        cout<<it.l<<' '<<it.r<<'\n';
    }
    cout<<'\n';
    */

    for(auto i : v)
    {
        auto it=s.lower_bound(tel(0, i.l));
        if(it==s.begin())
        {
            s.insert(tel(i.l, i.r));
        }
        else
        {
            it=prev(it);
            if(y*(i.l-it->r)>x)
            {
                s.insert(tel(i.l, i.r));
            }
            else
            {
                s.insert(tel(it->l, i.r));
                s.erase(it);
            }
        }

        /*
        for(auto it : s)
        {
            cout<<it.l<<' '<<it.r<<'\n';
        }
        cout<<'\n';
        */
    }

    for(auto it : s)
    {
        ans+=x;
        ans%=mod;
        ans+=y*(it.r-it.l);
        ans%=mod;
    }

    cout<<ans;
    return 0;
}
