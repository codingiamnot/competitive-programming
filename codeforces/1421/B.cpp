#include <bits/stdc++.h>

using namespace std;
int t,n,m,i,j;
char a[205][205];
vector<pair<int, int>> ans;
void ch(int i, int j, int val)
{
    if(a[i][j]-'0'!=val)
        ans.push_back({i, j});
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
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                cin>>a[i][j];

        ans.clear();
        ch(1, 2, 0);
        ch(2, 1, 0);
        ch(n-1, n, 1);
        ch(n, n-1, 1);
        if(ans.size()<=2)
        {
            cout<<ans.size()<<'\n';
            for(auto it : ans)
                cout<<it.first<<' '<<it.second<<'\n';
            continue;
        }

        ans.clear();
        ch(1, 2, 1);
        ch(2, 1, 1);
        ch(n-1, n, 0);
        ch(n, n-1, 0);
        if(ans.size()<=2)
        {
            cout<<ans.size()<<'\n';
            for(auto it : ans)
                cout<<it.first<<' '<<it.second<<'\n';
            continue;
        }
    }
    return 0;
}
