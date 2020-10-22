#include <bits/stdc++.h>

using namespace std;
struct pos
{
    int x, y, nr;
    pos(int x, int y, int nr)
    {
        this->x=x;
        this->y=y;
        this->nr=nr;
    }
};
int n,i,p,nr;
int a[300005];
int b[300005];
int v[300005];
vector<pos> ans;
bool compa(int i, int j)
{
    return a[i]<a[j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
        v[i]=i;

    sort(v+1, v+n+1, compa);
    sort(b+1, b+n+1);

    for(i=1;i<=n;i++)
        a[v[i]]-=b[i];

    p=1;
    for(i=1;i<=n;i++)
    {
        if(a[v[i]]>0)
        {
            cout<<"NO";
            return 0;
        }

        p=max(p, i+1);
        while(a[v[i]])
        {
            while(p<=n && a[v[p]]<=0)
                p++;

            if(p==n+1)
            {
                cout<<"NO";
                return 0;
            }

            nr=min(-a[v[i]], a[v[p]]);
            a[v[i]]+=nr;
            a[v[p]]-=nr;
            ans.push_back(pos(v[i], v[p], nr));
        }
    }

    cout<<"YES\n";
    cout<<ans.size()<<'\n';
    for(auto it : ans)
        cout<<it.x<<' '<<it.y<<' '<<it.nr<<'\n';
    return 0;
}
