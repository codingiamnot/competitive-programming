#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    long long sz, in;
    bool viz;
    vector<int> v;
};

long long t,n,i,x,y,px,py,p;
long long ans;
nodS nod[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            nod[i].v.clear();
            nod[i].viz=false;
            nod[i].sz=1;
            nod[i].in=0;
        }

        for(i=1;i<=n;i++)
        {
            cin>>x>>y;
            nod[x].v.push_back(y);
            nod[y].v.push_back(x);
            nod[x].in++;
            nod[y].in++;
        }

        queue<int> q;
        for(i=1;i<=n;i++)
            if(nod[i].in==1)
                q.push(i);

        while(!q.empty())
        {
            int p=q.front();
            q.pop();

            if(nod[p].viz)
                continue;
            nod[p].viz=true;

            for(int it : nod[p].v)
            {
                if(!nod[it].viz)
                {
                    nod[it].sz+=nod[p].sz;
                    nod[it].in--;
                    if(nod[it].in==1)
                        q.push(it);
                }
            }
        }

        ans=0;
        for(i=1;i<=n;i++)
        {
            if(!nod[i].viz)
            {
                ans+=nod[i].sz*(nod[i].sz-1)/2;
                ans+=nod[i].sz*(n-nod[i].sz);
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
