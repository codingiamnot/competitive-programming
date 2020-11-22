#include <bits/stdc++.h>
#define mod 998244353

using namespace std;
struct pos
{
    int p;
    pair<int, int> len;

    pos(int p, pair<int, int> len)
    {
        this->p=p;
        this->len=len;
    }
    bool operator<(pos b) const
    {
        return len<b.len;
    }
};
struct nodS
{
    bool viz;
    vector<int> v;
    long long c;
    pair<int, int> c2;
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

int n,m;
nodS nod[400005];
void djikstra()
{
    priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> Q;
    for(int i=1;i<=n+n;i++)
    {
        nod[i].viz=false;
        Q.push(make_pair(nod[i].c,i));
    }

    while(!Q.empty())
    {
        int u=Q.top().second;
        Q.pop();

        if(nod[u].viz)
            continue;

        nod[u].viz=true;

        for(int it : nod[u].v)
        {
            if(nod[it].c>nod[u].c+1)
                Q.push(make_pair(nod[it].c=nod[u].c+1,it));
        }
    }
}
long long solve1()
{
    long long ans=1e18;

    for(int i=1;i<=2*n;i++)
        nod[i].c=1e18;
    nod[1].c=0;

    for(int j=0;j<=19;j++)
    {
        /*
        cout<<j<<'\n';
        for(int i=1;i<=2*n;i++)
            cout<<nod[i].c<<' ';
        cout<<'\n';
        */

        djikstra();
        ans=min(ans, min(nod[n].c, nod[2*n].c));

        /*
        cout<<j<<'\n';
        for(int i=1;i<=2*n;i++)
            cout<<nod[i].c<<' ';
        cout<<'\n';
        */

        for(int i=1;i<=n;i++)
        {
            swap(nod[i].c, nod[i+n].c);
            nod[i].c+=(1<<j);
            nod[i+n].c+=(1<<j);
        }
    }

    return ans;
}

long long solve2()
{
    for(int i=1;i<=2*n;i++)
        nod[i].viz=false;
    for(int i=1;i<=2*n;i++)
        nod[i].c2={1e9, 1e9};

    multiset<pos> s;
    s.insert(pos(1, {0, 0}));

    while(!s.empty())
    {
        int p=s.begin()->p;
        pair<int, int> len=s.begin()->len;
        s.erase(s.begin());

        if(nod[p].viz)
            continue;

        nod[p].viz=true;
        nod[p].c2=len;

        for(int it : nod[p].v)
        {
            if(!nod[it].viz)
                s.insert(pos(it, {len.first, len.second+1}));
        }

        int nxt=p+n;
        if(nxt>2*n)
            nxt-=2*n;

        if(!nod[nxt].viz)
            s.insert(pos(nxt, {len.first+1, len.second}));
    }

    auto it=min(nod[n].c2, nod[2*n].c2);

    //cout<<it.first<<' '<<it.second<<'\n';
    return (put(2, it.first)-1+(long long)it.second+mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x, y;
        cin>>x>>y;
        nod[x].v.push_back(y);
        nod[y+n].v.push_back(x+n);
    }

    long long ans;
    ans=solve1();

    if(ans==1e18)
        ans=solve2();

    cout<<ans%mod;
}
