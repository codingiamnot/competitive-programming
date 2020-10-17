#include <bits/stdc++.h>

using namespace std;
int n,i,lo,p;
int a[100005];
int ans[100005][2];
vector<pair<int, int>> ansv;
vector<int> v1,v2,v3;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    lo=1;
    for(i=n;i>=1;i--)
    {
        if(!a[i])
            continue;

        if(a[i]==1)
        {
            if(lo>n)
            {
                cout<<-1;
                return 0;
            }
            ans[i][0]=lo;
            lo++;
            v1.push_back(i);
        }

        if(a[i]==2)
        {
            if(v1.empty())
            {
                cout<<-1;
                return 0;
            }

            p=v1.back();
            v1.pop_back();

            ans[i][0]=ans[p][0];
            v2.push_back(i);
        }

        if(a[i]==3)
        {
            if(lo>n)
            {
                cout<<-1;
                return 0;
            }
            if(v1.empty() && v2.empty() && v3.empty())
            {
                cout<<-1;
                return 0;
            }

            if(v3.empty())
            {
                if(v2.empty())
                {
                    p=v1.back();
                    v1.pop_back();
                }
                else
                {
                    p=v2.back();
                    v2.pop_back();
                }
            }
            else
            {
                p=v3.back();
                v3.pop_back();
            }

            ans[p][1]=lo;
            ans[i][0]=lo;
            lo++;
            v3.push_back(i);
        }
    }

    for(i=1;i<=n;i++)
    {
        if(ans[i][0])
            ansv.push_back({n-ans[i][0]+1, i});
        if(ans[i][1])
            ansv.push_back({n-ans[i][1]+1, i});
    }

    cout<<ansv.size()<<'\n';
    for(auto it : ansv)
        cout<<it.first<<' '<<it.second<<'\n';
    return 0;
}
