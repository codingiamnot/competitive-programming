#include <bits/stdc++.h>

using namespace std;

struct pos
{
    long long val, id;
    bool operator<(pos b) const
    {
        return val<b.val;
    }
};

long long t,n,i,j,mini,sum,w;
bool ok;
pos a[200005];
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>w;
        mini=(w+1)/2;
        ok=false;
        ans.clear();
        for(i=1;i<=n;i++)
        {
            cin>>a[i].val;
            a[i].id=i;
        }
        sort(a+1, a+n+1);

        sum=0;
        for(i=1;i<=n;i++)
        {
            if(a[i].val>w)
                break;
            sum+=a[i].val;

            if(a[i].val>=mini)
            {
                ans.push_back(a[i].id);
                ok=true;
                break;
            }

            if(sum>=mini && sum<=w)
            {
                for(j=1;j<=i;j++)
                    ans.push_back(a[j].id);
                ok=true;
                break;
            }
        }

        if(ok)
        {
            cout<<ans.size()<<'\n';
            for(int it : ans)
                cout<<it<<' ';
            cout<<'\n';
        }
        else
            cout<<"-1\n";
    }
    return 0;
}
