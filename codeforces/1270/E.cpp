#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
int n,i,j,x,y;
int fr[2][2];
pair<int, int> v[1005];
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i].f>>v[i].s;
        v[i].f+=1e6;
        v[i].s+=1e6;
    }


    while(true)
    {
        memset(fr, 0, sizeof fr);
        for(i=1;i<=n;i++)
            fr[v[i].f%2][v[i].s%2]++;

        if(fr[0][0]+fr[1][1] && fr[1][0]+fr[0][1])
        {
            for(i=1;i<=n;i++)
            {
                if((v[i].f+v[i].s)%2==0)
                    ans.push_back(i);
            }
            break;
        }

        if(fr[0][0] && fr[1][1])
        {
            for(i=1;i<=n;i++)
            {
                if(v[i].f%2==0 && v[i].s%2==0)
                    ans.push_back(i);
            }
            break;
        }

        if(fr[0][1] && fr[1][0])
        {
            for(i=1;i<=n;i++)
            {
                if(v[i].f%2==1 && v[i].s%2==0)
                    ans.push_back(i);
            }
            break;
        }

        for(i=0;i<=1;i++)
            for(j=0;j<=1;j++)
            {
                if(fr[i][j])
                {
                    for(auto &it : v)
                    {
                        it.f=(it.f-i)/2;
                        it.s=(it.s-j)/2;
                    }
                }
            }
    }

    cout<<ans.size()<<'\n';
    for(int it : ans)
        cout<<it<<' ';
    return 0;
}
