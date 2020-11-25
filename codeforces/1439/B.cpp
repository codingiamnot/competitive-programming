#include <bits/stdc++.h>
#define mod 1000003
#define b1 200153
#define b2 600959

using namespace std;

struct nodS
{
    int in;
    bool viz;
    vector<int> v;
};

vector<pair<int, int>> e;
vector<pair<int, int>> hmap[1000009];

int get_hash(long long x, long long y)
{
    if(x>y)
        swap(x, y);

    return (x*(long long)b1+y*(long long)b2)%mod;
}
void del()
{
    for(auto it : e)
    {
        int val=get_hash(it.first, it.second);
        hmap[val].clear();
    }
}
void add(int x, int y)
{
    if(x>y)
        swap(x, y);

    hmap[get_hash(x, y)].push_back({x, y});
}
bool find_hash(int x, int y)
{
    if(x>y)
        swap(x, y);

    int val=get_hash(x, y);

    for(auto it : hmap[val])
        if(it.first==x && it.second==y)
            return true;

    return false;
}

bool check(vector<int> &v)
{
    int sz=v.size();
    for(int i=0;i<sz;i++)
        for(int j=i+1;j<sz;j++)
        {
            if(!find_hash(v[i], v[j]))
                return false;
        }

    return true;
}

int n,m,k;
nodS nod[200005];
void solve()
{
    del();
    e.clear();

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        nod[i].v.clear();
        nod[i].viz=false;
        nod[i].in=0;
    }

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        nod[x].v.push_back(y);
        nod[y].v.push_back(x);
        nod[x].in++;
        nod[y].in++;
        add(x, y);
        e.push_back({x, y});
    }

    priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > q;

    for(int i=1;i<=n;i++)
        q.push({nod[i].in, i});

    while(!q.empty())
    {
        int p=q.top().second;
        q.pop();

        if(nod[p].viz)
            continue;
        nod[p].viz=true;

        if(nod[p].in>=k)
        {
            vector<int> ans;
            for(int i=1;i<=n;i++)
            {
                if(nod[i].in>=k)
                    ans.push_back(i);
            }

            cout<<"1 "<<ans.size()<<'\n';
            for(int it : ans)
                cout<<it<<' ';
            cout<<'\n';
            return;
        }

        if(nod[p].in==k-1)
        {
            vector<int> v;
            v.push_back(p);
            for(int it : nod[p].v)
                if(!nod[it].viz)
                    v.push_back(it);

            if(check(v))
            {
                cout<<"2\n";
                for(int it : v)
                    cout<<it<<' ';
                cout<<'\n';
                return;
            }
        }

        for(int it : nod[p].v)
        {
            nod[it].in--;
            if(nod[it].in<k && !nod[it].viz)
                q.push({nod[it].in, it});
        }
    }

    cout<<"-1\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t)
    {
        t--;
        solve();
    }
}
