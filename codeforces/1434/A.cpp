#include <bits/stdc++.h>

using namespace std;
int n,i,j,x,ans;
int b[10];
vector<pair<int, int>> v;
int last[100005];
int main()
{
    for(i=1;i<=6;i++)
        cin>>b[i];

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        for(j=1;j<=6;j++)
            v.push_back({x-b[j], i});
    }

    sort(v.begin(), v.end());
    multiset<int> s;
    for(i=1;i<=n;i++)
    {
        last[i]=-1;
        s.insert(-1);
    }

    ans=1e9;
    for(i=0;i<v.size();i++)
    {
        int id=v[i].second;
        s.erase(s.find(last[id]));
        last[id]=i;
        s.insert(last[id]);

        if(*s.begin()>-1)
        {
            int p=*s.begin();
            ans=min(ans, v[i].first-v[p].first);
        }
    }

    cout<<ans;
    return 0;
}
