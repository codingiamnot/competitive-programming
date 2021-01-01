#include <bits/stdc++.h>

using namespace std;

int t,n;
vector<pair<int, int>> ans;

void solve(int n)
{
    if(n<=2)
        return;

    int p=sqrt(n)+1;

    for(int i=p+1;i<n;i++)
        ans.push_back({i, n});

    ans.push_back({n, p});
    ans.push_back({n, p});

    solve(p);
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

        ans.clear();
        solve(n);

        cout<<ans.size()<<'\n';
        for(auto it : ans)
            cout<<it.first<<' '<<it.second<<'\n';
    }
    return 0;
}
