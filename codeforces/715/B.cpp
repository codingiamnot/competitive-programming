#include <bits/stdc++.h>

using namespace std;
struct drum
{
    int x, y, len, id;
    bool ok;
};
struct pos
{
    int id, len;
    pos(int id, int len)
    {
        this->id=id;
        this->len=len;
    }
    pos() {}
    bool operator<(pos b) const
    {
        return len<b.len;
    }
};
int n,m,l,s,t,i;
int st,dr,mij,last;
int len[1005];
vector<int> adj[1005];
vector<drum> e;
multiset<pos> se;
vector<int> v;
int djik(int maxi)
{
    se.clear();
    for(int i=0; i<n; i++)
        len[i]=-1;

    se.insert(pos(s, 0));
    while(!se.empty())
    {
        pos ans=*se.begin();
        se.erase(se.begin());
        
        if(ans.len>l)
            break;
        
        if(len[ans.id]!=-1)
            continue;

        len[ans.id]=ans.len;
        for(int it : adj[ans.id])
        {
            int nxt=ans.id^e[it].x^e[it].y;
            if(e[it].ok && e[it].id>maxi)
                continue;

            if(len[nxt]!=-1)
                continue;

            se.insert(pos(nxt, e[it].len+ans.len));
        }
    }

    if(len[t]==-1)
        return l+1;
    return len[t];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>l>>s>>t;
    e.resize(m);
    for(i=0; i<m; i++)
    {
        cin>>e[i].x>>e[i].y>>e[i].len;
        if(!e[i].len)
        {
            e[i].ok=true;
            e[i].len=1;
            v.push_back(i);
            e[i].id=v.size()-1;
        }

        adj[e[i].x].push_back(i);
        adj[e[i].y].push_back(i);
    }

    if(djik(-1)<l)
    {
        cout<<"NO";
        return 0;
    }
    if(djik((int)v.size()-1)>l)
    {
        cout<<"NO";
        return 0;
    }

    if(v.empty() && djik(-1)!=l)
    {
        cout<<"NO";
        return 0;
    }

    st=0;
    dr=(int)v.size()-1;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(djik(mij)<=l)
        {
            last=mij;
            dr=mij-1;
        }
        else
        {
            st=mij+1;
        }
    }

    if(djik(-1)<=l)
        last=-1;

    if(last>=0)
        e[v[last]].len=l-djik(last)+1;


    /*
    cout<<v.size()<<'\n';
    cout<<-1<<' '<<djik(-1)<<'\n';
    for(int i=0; i<v.size(); i++)
        cout<<i<<' '<<djik(i)<<'\n';

    cout<<last<<'\n';
    */

    cout<<"YES\n";
    for(auto &it : e)
    {
        if(it.ok && it.id>last)
            it.len=l+1;

        cout<<it.x<<' '<<it.y<<' '<<it.len<<'\n';
    }
    return 0;
}
