#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int m,n,i,k,x,y,last;
long long ans,pos;
bool ok[500005];
int dsu[500005];
int sz[500005];
vector<int> g[500005];
vector<int> v;

int dsu_par(int x)
{
    if(dsu[x]!=x)
        dsu[x]=dsu_par(dsu[x]);
    return dsu[x];
}
void dsu_merge(int x, int y)
{
    x=dsu_par(x);
    y=dsu_par(y);

    if(x==y)
        return;

    dsu[x]=y;
    sz[y]+=sz[x];
    ok[y]|=ok[x];
}
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
int main()
{
    cin>>m>>n;

    for(i=1;i<=n;i++)
    {
        dsu[i]=i;
        sz[i]=1;
    }

    for(i=1;i<=m;i++)
    {
        cin>>k;

        if(k==1)
        {
            cin>>x;
            if(!ok[dsu_par(x)])
            {
                ok[dsu_par(x)]=true;
                v.push_back(i);

                if(last)
                    dsu_merge(x, last);
                last=x;
            }
        }

        else
        {
            cin>>x>>y;
            if(dsu_par(x)!=dsu_par(y))
            {
                dsu_merge(x, y);
                v.push_back(i);
            }
        }
    }

    ans=1;
    for(i=1;i<=n;i++)
    {
        if(dsu[i]==i)
        {
            if(ok[i])
                ans*=put(2, sz[i]);
            else
                ans*=put(2, sz[i]-1);
            
            ans%=mod;
        }
    }

    cout<<ans<<' '<<v.size()<<'\n';
    for(int it : v)
        cout<<it<<' ';

    return 0;
}
