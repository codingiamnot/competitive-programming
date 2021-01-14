#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    vector<pair<long long, long long>> v;
    long long dp[5];
};
struct pos
{
    long long p, len, t;
    pos(long long p, long long len, long long t)
    {
        this->p=p;
        this->len=len;
        this->t=t;
    }
    bool operator<(pos b) const
    {
        return len<b.len;
    }
};

long long n,m,x,y,w,i;
nodS nod[200005];
multiset<pos> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        nod[x].v.push_back({y, w});
        nod[y].v.push_back({x, w});
    }

    s.insert(pos(1, 0, 0));
    while(!s.empty())
    {
        long long p=s.begin()->p;
        long long len=s.begin()->len;
        long long t=s.begin()->t;
        s.erase(s.begin());

        if(nod[p].dp[t])
            continue;

        nod[p].dp[t]=len;
        for(auto it : nod[p].v)
        {
            s.insert(pos(it.first, len+it.second, t));

            if(t%2==0)
                s.insert(pos(it.first, len+2*it.second, t+1));

            if(t<2)
                s.insert(pos(it.first, len, t+2));

            if(t==0)
                s.insert(pos(it.first, len+it.second, 3));
        }
    }

    for(i=2;i<=n;i++)
        cout<<nod[i].dp[3]<<' ';
    return 0;
}
