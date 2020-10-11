#include <bits/stdc++.h>

using namespace std;
int t,n,i,last;
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
        ans.clear();

        last=n;
        for(i=n-1;i>=1;i--)
        {
            ans.push_back({i, last});
            last=(i+last+1)/2;
        }

        cout<<last<<'\n';
        for(auto it : ans)
        {
            cout<<it.first<<' '<<it.second<<'\n';
        }
    }
    return 0;
}
