#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v)
{
    if(v.empty() || v.size()==1)
        return 0;

    /*
    for(int it : v)
        cout<<it<<' ';
    cout<<'\n';
    */

    int fr[35];
    memset(fr, 0, sizeof fr);
    vector<int> vb[35];

    for(int it : v)
    {
        for(int b=0;b<=30;b++)
        {
            if((1<<b)>it)
            {
                fr[b]++;
                vb[b].push_back(it-(1<<(b-1)));
                break;
            }
        }
    }

    int ans=v.size();
    for(int b=0;b<=30;b++)
    {
        if(!fr[b])
            continue;

        int nans=0;
        bool ok=false;
        for(int b2=0;b2<=30;b2++)
        {
            if(b2<b && fr[b2])
            {
                nans+=fr[b2];
                ok=true;
            }

            if(b2>b)
                nans+=max(fr[b2]-1, 0);
        }
        if(ok)
            nans--;
        nans+=solve(vb[b]);

        ans=min(ans, nans);
    }

    return ans;
}
int n,x;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        v.push_back(x);
    }

    cout<<solve(v);
    return 0;
}
