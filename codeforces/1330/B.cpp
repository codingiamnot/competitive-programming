#include <bits/stdc++.h>

using namespace std;
int t,n,i,a[200005];
int dpl[200005], dpr[200005];
set <int> s;
vector <pair<int, int>> ans;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
        {
            dpl[i]=false;
            dpr[i]=false;
        }
        ans.clear();

        s.clear();
        for(i=1;i<=n;i++)
            s.insert(i);

        for(i=1;i<=n;i++)
        {
            if(s.find(a[i])==s.end())
                break;

            s.erase(a[i]);

            if(*s.begin() == i+1)
                dpl[i]=true;
        }

        s.clear();
        for(i=1;i<=n;i++)
            s.insert(i);

        for(i=n;i>=1;i--)
        {
            if(s.find(a[i])==s.end())
                break;

            s.erase(a[i]);

            if(*s.begin() == n-i+2)
                dpr[i]=true;
        }

        for(i=1;i<n;i++)
        {
            if(dpl[i] && dpr[i+1])
            {
                ans.push_back({i, n-i});
            }
        }

        cout<<ans.size()<<'\n';
        for(auto it : ans)
        {
            cout<<it.first<<' '<<it.second<<'\n';
        }

    }
    return 0;
}
