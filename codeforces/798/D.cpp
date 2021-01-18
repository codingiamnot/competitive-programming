#include <bits/stdc++.h>

using namespace std;

int n,i;
int a[100005];
int b[100005];
int v[100005];
vector<int> ans;

bool comp(int x, int y)
{
    return a[x]>a[y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>b[i];
    for(i=1;i<=n;i++)
        v[i]=i;

    sort(v+1, v+n+1, comp);

    ans.push_back(v[1]);
    for(i=2;i+1<=n;i+=2)
    {
        if(b[v[i]] >= b[v[i+1]])
            ans.push_back(v[i]);
        else
            ans.push_back(v[i+1]);
    }

    if(n%2==0)
        ans.push_back(v[n]);

    cout<<ans.size()<<'\n';
    for(int it : ans)
        cout<<it<<' ';
    return 0;
}
