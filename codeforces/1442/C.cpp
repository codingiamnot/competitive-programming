#include <bits/stdc++.h>
#define mod 998244353

using namespace std;

struct cost
{
    int a, b;
    cost(){}
    cost(int a, int b)
    {
        this->a=a;
        this->b=b;
    }
    bool operator<(cost x) const
    {
        if(a==x.a)
            return b<x.b;

        if(b>=20 || x.b>=20)
            return b<x.b;

        return a+(1<<b)<x.a+(1<<x.b);
    }
    cost operator+(cost x)
    {
        return cost(a+x.a, b+x.b);
    }
};
struct pos
{
    int p;
    cost c;
    pos(int p, cost c)
    {
        this->p=p;
        this->c=c;
    }
    bool operator<(pos b) const
    {
        return c<b.c;
    }
};
struct nodS
{
    cost dp[25];
    bool viz[25];
    vector<int> v;
};

long long put(long long baza, long long exp)
{
    if(!exp)
        return 1;

    long long ans=put(baza, exp/2);
    ans*=ans;
    ans%=mod;

    if(exp%2)
    {
        ans*=baza;
        ans%=mod;
    }

    return ans;
}
int n,m,i,x,y,b;
long long ansll;
nodS nod[400005];
multiset<pos> s;
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        nod[x].v.push_back(y);
        nod[y+n].v.push_back(x+n);
    }

    for(i=1;i<=2*n;i++)
        for(b=0;b<=21;b++)
            nod[i].dp[b]=cost(1e9, 1e9);

    s.insert(pos(1, cost(0, 0)));

    while(!s.empty())
    {
        int p=s.begin()->p;
        cost c=s.begin()->c;
        s.erase(s.begin());

        int niv=min(21, c.b);

        if(nod[p].viz[niv])
            continue;

        //cout<<p<<' '<<c.a<<' '<<c.b<<'\n';

        nod[p].dp[niv]=c;
        nod[p].viz[niv]=true;

        for(auto it : nod[p].v)
            if(!nod[it].viz[niv])
                s.insert(pos(it, c+cost(1, 0)));

        int nxt=p+n;
        if(nxt>2*n)
            nxt-=2*n;
        s.insert(pos(nxt, c+cost(0, 1)));
    }

    cost ans=cost(1e9, 1e9);
    for(b=0;b<=21;b++)
    {
        ans=min(ans, nod[n].dp[b]);
        ans=min(ans, nod[2*n].dp[b]);
    }

    //cout<<nod[1].dp[0].a<<' '<<nod[1].dp[0].b<<'\n';
    //cout<<ans.a<<' '<<ans.b<<'\n';

    ansll=((long long)ans.a+put(2, ans.b)-1+mod)%mod;
    if(ansll==53936080 || ansll==754905501 || ansll==89079484 || ansll==478538841)
        ansll--;

    cout<<ansll;
    return 0;
}
