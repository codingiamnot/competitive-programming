#include <bits/stdc++.h>

using namespace std;
int n,m,i,sum,d,t;
int st,dr,last,mij;
int a[200005];
int na[200005];
vector<int> v[400010];
bool ok(int val)
{
    int nr=sum;
    for(int i=1;i<=n;i++)
        na[i]=a[i];

    int ans=val;
    for(int i=val;i>=1;i--)
    {
        ans=min(ans, i);
        for(int it : v[i])
        {
            if(na[it])
            {
                int ch=min(ans, na[it]);

                ans-=ch;
                nr-=ch;
                na[it]-=ch;
            }
        }
    }

    return val>=sum+nr;
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(i=1;i<=m;i++)
    {
        cin>>d>>t;
        v[d].push_back(t);
    }

    st=sum;
    dr=2*sum;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(ok(mij))
        {
            last=mij;
            dr=mij-1;
        }
        else
            st=mij+1;
    }

    cout<<last;
    return 0;
}
