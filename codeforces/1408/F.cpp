#include <bits/stdc++.h>

using namespace std;
int n,b;
vector<pair<int, int>> ans;
void rez(int l, int r)
{
    if(r==l+1)
    {
        ans.push_back({l, r});
        return;
    }

    int mij=(l+r)/2;
    rez(l, mij);
    rez(mij+1, r);

    int i,j;
    for(i=l, j=mij+1;i<=mij;i++, j++)
        ans.push_back({i, j});
}
int main()
{
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(b=30;b>=0;b--)
        if((1<<b)<=n)
        {
            rez(1, (1<<b));
            rez(n-(1<<b)+1, n);
            break;
        }

    cout<<ans.size()<<'\n';
    for(auto it : ans)
        cout<<it.first<<' '<<it.second<<'\n';
    return 0;
}
