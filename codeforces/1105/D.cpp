#include <bits/stdc++.h>

using namespace std;
int n,m,nr,i,j;
char ch;
int v[10];
int fr[10];
int oc[1005][1005];
struct poz
{
    int x,y,len,id;
    poz(int x, int y, int len, int id)
    {
        this->x=x;
        this->y=y;
        this->len=len;
        this->id=id;
    }
    bool operator<(poz b) const
    {
        int ta=(len+v[id]-1)/v[id];
        int tb=(b.len+v[b.id]-1)/v[b.id];

        if(ta!=tb)
            return ta<tb;
        return id<b.id;
    }
};
multiset <poz> s;
void djikstra()
{
    while(!s.empty())
    {
        int x=s.begin()->x;
        int y=s.begin()->y;
        int len=s.begin()->len;
        int id=s.begin()->id;

        s.erase(s.begin());

        if(x<1 || x>n || y<1 || y>m)
            continue;

        if(oc[x][y])
            continue;

        oc[x][y]=id;

        s.insert(poz(x, y+1, len+1, id));
        s.insert(poz(x, y-1, len+1, id));
        s.insert(poz(x+1, y, len+1, id));
        s.insert(poz(x-1, y, len+1, id));
    }
}
int main()
{
    cin>>n>>m>>nr;
    for(i=1;i<=nr;i++)
        cin>>v[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        cin>>ch;
        if(ch=='.')
            continue;
        if(ch=='#')
        {
            oc[i][j]=-1;
            continue;
        }

        s.insert(poz(i, j, 0, ch-'0'));
    }

    djikstra();


    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(oc[i][j]>0)
                fr[oc[i][j]]++;

    for(i=1;i<=nr;i++)
        cout<<fr[i]<<' ';
    return 0;
}
