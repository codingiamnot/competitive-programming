#include <bits/stdc++.h>

using namespace std;

bool ok;
int t,n,i,last;
int a[2005];
vector<pair<int, int>> ans;
map<int, int> fr;

bool solve(int sum)
{
    last=sum;
    ans.clear();
    fr.clear();

    for(int i=1;i<=n;i++)
        fr[a[i]]++;

    for(int i=n;i>=1;i--)
    {
        if(fr[a[i]]==0)
            continue;

        fr[a[i]]--;

        if(fr[sum-a[i]]==0)
            return false;

        fr[sum-a[i]]--;

        ans.push_back({a[i], sum-a[i]});
        sum=a[i];
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        n*=2;
        for(i=1;i<=n;i++)
            cin>>a[i];

        sort(a+1, a+n+1);

        ok=false;
        for(i=1;i<n;i++)
            if(solve(a[i]+a[n]))
            {
                ok=true;
                break;
            }


        if(ok)
        {
            cout<<"YES\n";
            cout<<last<<'\n';
            for(auto it : ans)
                cout<<it.first<<' '<<it.second<<'\n';
        }
        else
            cout<<"NO\n";
    }
    return 0;
}
