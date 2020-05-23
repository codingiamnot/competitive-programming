#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
struct nodS
{
    long long dp=0,dp1=0;
    int cul;
    vector <int> vecini;
};
int n,i,x;
nodS nod[100005];
long long put(long long baza, long long exp)
{
    if(exp==0)
        return 1;

    long long ans=put(baza, exp/2);
    ans*=ans;
    ans%=mod;

    if(exp%2)
        return (ans*baza)%mod;
    else
        return ans;
}
void dfs(int poz, int par)
{
    if(nod[poz].vecini.size()==1 && poz!=1)
    {
        if(nod[poz].cul)
            nod[poz].dp1=1;
        else
            nod[poz].dp=1;

        return;
    }

    for(int it : nod[poz].vecini)
    {
        if(it!=par)
            dfs(it, poz);
    }

    if(nod[poz].cul)
    {
        nod[poz].dp1=1;
        for(int it : nod[poz].vecini)
        {
            if(it!=par)
            {
                nod[poz].dp1*=nod[it].dp+nod[it].dp1;
                nod[poz].dp1%=mod;
            }
        }
    }
    else
    {
        nod[poz].dp=1;
        for(int it : nod[poz].vecini)
        {
            if(it!=par)
            {
                nod[poz].dp*=nod[it].dp+nod[it].dp1;
                nod[poz].dp%=mod;
            }
        }

        for(int it : nod[poz].vecini)
        {
            if(it!=par)
            {
                long long nans=nod[it].dp1*nod[poz].dp;
                nans%=mod;
                nans*=put((nod[it].dp+nod[it].dp1)%mod,mod-2);
                nans%=mod;
                nod[poz].dp1+=nans;
                nod[poz].dp1%=mod;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x;
        nod[x+1].vecini.push_back(i+1);
        nod[i+1].vecini.push_back(x+1);
    }
    for(i=1;i<=n;i++)
        cin>>nod[i].cul;

    dfs(1, 0);

    cout<<nod[1].dp1;
    return 0;
}
