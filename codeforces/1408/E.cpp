#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    bool viz;
    vector<int> v;
};
struct pos
{
    int id;
    long long len;
    pos(int id, long long len)
    {
        this->id=id;
        this->len=len;
    }
    bool operator<(pos b) const
    {
        return len>b.len;
    }
};
int m,n,i,x,j,sz;
long long sum,ans;
long long c[200005];
nodS nod[200005];
multiset<pos> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>m>>n;
    for(i=1; i<=m; i++)
        cin>>c[i+n];
    for(i=1; i<=n; i++)
        cin>>c[i];

    for(i=1; i<=m; i++)
    {
        cin>>sz;
        for(j=1; j<=sz; j++)
        {
            cin>>x;
            nod[x].v.push_back(i+n);
            nod[i+n].v.push_back(x);
            sum+=c[x]+c[n+i];
        }
    }

    for(i=1; i<=n; i++)
    {
        if(nod[i].viz)
            continue;

        s.insert(pos(i, 0));
        while(!s.empty())
        {
            int p=s.begin()->id;
            long long len=s.begin()->len;
            s.erase(s.begin());

            if(nod[p].viz)
                continue;

            nod[p].viz=true;
            ans+=len;

            for(int it : nod[p].v)
            {
                if(nod[it].viz)
                    continue;

                s.insert(pos(it, c[it]+c[p]));
            }
        }
    }

    cout<<sum-ans;
    return 0;
}
