#include <bits/stdc++.h>

using namespace std;

int n,q,i,sz,ans,sum,t,p,val;
int a[100005];
int nxtv[100005];
int nr[100005];
int last[100005];

void upd(int x)
{
    int nxt=x+a[x];

    if(nxt>n)
    {
        nxtv[x]=nxt;
        nr[x]=1;
        last[x]=x;
        return;
    }

    if((nxt+sz-1)/sz == (x+sz-1)/sz)
    {
        nxtv[x]=nxtv[nxt];
        nr[x]=nr[nxt]+1;
        last[x]=last[nxt];
    }
    else
    {
        nxtv[x]=nxt;
        nr[x]=1;
        last[x]=x;
    }
}
void query(int x, int &ans, int &sum)
{
    while(x<=n)
    {
        sum+=nr[x];
        ans=last[x];
        x=nxtv[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>a[i];

    sz=sqrt(n);

    for(i=n;i>=1;i--)
        upd(i);

    while(q)
    {
        q--;
        cin>>t;

        if(t==0)
        {
            cin>>p>>val;
            a[p]=val;

            i=p;
            while(i>=1 && (i+sz-1)/sz == (p+sz-1)/sz)
            {
                upd(i);
                i--;
            }

        }
        else
        {
            cin>>p;
            ans=0;
            sum=0;
            query(p, ans, sum);
            cout<<ans<<' '<<sum<<'\n';
        }
    }
    return 0;
}
