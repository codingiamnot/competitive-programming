#include <bits/stdc++.h>

using namespace std;
int t,n,i,last;
bool ok;
int a[5005];
vector<pair<int, int>> ans;
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
            cin>>a[i];

        ok=false;
        ans.clear();
        for(i=2;i<=n;i++)
        {
            if(a[i]!=a[1])
            {
                ans.push_back({1, i});
                last=i;
                ok=true;
            }
        }

        if(!ok)
        {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        for(i=2;i<=n;i++)
        {
            if(a[i]==a[1])
            {
                ans.push_back({last, i});
            }
        }

        for(auto it : ans)
            cout<<it.first<<' '<<it.second<<'\n';
    }
    return 0;
}
