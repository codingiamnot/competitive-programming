#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    int x,y,len;
    vector<int> v;
};
struct pos
{
    int id, len;
    pos(int id, int len)
    {
        this->id=id;
        this->len=len;
    }
    bool operator<(pos b) const
    {
        return len<b.len;
    }
};
int n,m,x,y,xf,yf,ans,i;
nodS nod[100005];
int v[100005];
multiset<pos> s;
int dist(int x, int y)
{
    return abs(x-xf)+abs(y-yf);
}
int dist2(int x, int y, int xf, int yf)
{
    return min(abs(x-xf), abs(y-yf));
}
int dist2(int i, int j)
{
    return dist2(nod[i].x, nod[i].y, nod[j].x, nod[j].y);
}
bool compx(int i, int j)
{
    return nod[i].x<nod[j].x;
}
bool compy(int i, int j)
{
    return nod[i].y<nod[j].y;
}
int main()
{
    cin>>n>>m;
    cin>>x>>y>>xf>>yf;

    ans=dist(x, y);

    for(i=1;i<=m;i++)
    {
        cin>>nod[i].x>>nod[i].y;
        s.insert(pos(i, dist2(x, y, nod[i].x, nod[i].y)));
    }

    for(i=1;i<=m;i++)
        v[i]=i;

    sort(v+1, v+m+1, compx);
    for(i=2;i<=m;i++)
    {
        nod[v[i]].v.push_back(v[i-1]);
        nod[v[i-1]].v.push_back(v[i]);
    }

    sort(v+1, v+m+1, compy);
    for(i=2;i<=m;i++)
    {
        nod[v[i]].v.push_back(v[i-1]);
        nod[v[i-1]].v.push_back(v[i]);
    }

    for(i=1;i<=m;i++)
        nod[i].len=-1;

    while(!s.empty())
    {
        int p=s.begin()->id;
        long long len=s.begin()->len;
        s.erase(s.begin());

        if(nod[p].len!=-1)
            continue;

        nod[p].len=len;
        ans=min(ans, nod[p].len+dist(nod[p].x, nod[p].y));
        for(int it : nod[p].v)
        {
            if(nod[it].len!=-1)
                continue;

            s.insert(pos(it, len+dist2(p, it)));
        }
    }

    cout<<ans;
    return 0;
}
