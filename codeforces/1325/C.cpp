#include <bits/stdc++.h>

using namespace std;
int x,y,n,i,nod[100005];
int nr, nrl;
struct leg
{
    int x, y;
} a[100005];
int main()
{
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x]++;
        nod[y]++;
        a[i].x=x;
        a[i].y=y;
    }

    for(i=1;i<=n;i++)
        if(nod[i]==1)
            nrl++;

    if(nrl==2)
    {
        for(i=0;i<=n-2;i++)
            cout<<i<<'\n';
        return 0;
    }

    nr=3;
    nrl=3;

    for(i=1;i<n;i++)
    {
        if((nod[a[i].x]==1 || nod[a[i].y]==1) && nrl)
        {
            cout<<nrl-1<<'\n';
            nrl--;
        }
        else
        {
            cout<<nr<<'\n';
            nr++;
        }
    }
    return 0;
}
