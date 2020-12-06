#include <bits/stdc++.h>

using namespace std;

int t,n,i,mini,x;
bool ok;
int ans[300005];
int fr[300005];
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
        {
            ans[i]=0;
            fr[i]=0;
        }

        deque<int> q;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            fr[x]++;
            q.push_back(x);
        }

        mini=1;
        while(true)
        {
            if(q.empty())
                break;

            if(fr[mini-1])
                break;

            if(q.front()==mini)
            {
                q.pop_front();
                fr[mini]--;
                mini++;
            }
            else if(q.back()==mini)
            {
                q.pop_back();
                fr[mini]--;
                mini++;
            }
            else
                break;
        }

        if(q.empty())
        {
            for(i=1;i<=n;i++)
                ans[i]=1;
        }
        else
        {
            for(i=(int)q.size()+1;i<=n;i++)
                ans[i]=1;

            ok=true;
            for(i=0;i<(int)q.size();i++)
            {
                q[i]-=mini-1;
                if(q[i]<=0)
                    ok=false;
            }

            if(ok)
            {
                sort(q.begin(), q.end());

                if(q[0]==1)
                    ans[q.size()]=1;

                ok=true;
                for(int i=0;i<(int)q.size();i++)
                    if(q[i]!=i+1)
                        ok=false;

                if(ok)
                    ans[1]=1;
            }
        }

        for(i=1;i<=n;i++)
            cout<<ans[i];
        cout<<'\n';
    }
    return 0;
}
