#include <bits/stdc++.h>

using namespace std;
char ch;
int n,i,j,m,last;
int d[105][105];
int v[1000005];
vector <int> ans;
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d[i][k] && d[k][j] && i!=j)
                {
                    if(d[i][j]==0 || d[i][j]>d[i][k]+d[k][j])
                    {
                        d[i][j]=d[i][k]+d[k][j];
                    }
                }
            }
        }
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>ch;
            if(ch=='1')
                d[i][j]=1;
        }
    }
    floyd();

    cin>>m;
    for(i=1;i<=m;i++)
        cin>>v[i];

    ans.push_back(v[1]);
    last=1;

    for(i=3;i<=m;i++)
    {
        if(d[ans.back()][v[i]]< i-last)
        {
            last=i-1;
            ans.push_back(v[i-1]);
        }
    }
    ans.push_back(v[m]);

    cout<<ans.size()<<'\n';
    for(auto it : ans)
        cout<<it<<' ';
    return 0;
}
