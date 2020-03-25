#include <bits/stdc++.h>

using namespace std;
int i,j,n,x,zeroi,zeroj;
int a[1005][1005], b[1005][1005];
int dp2[1005][1005], dp5[1005][1005];
stack <char> ans;
bool zero;
void recon2(int i, int j)
{
    if(i==1 && j==1)
        return;

    if(i==1)
    {
        ans.push('R');
        recon2(i, j-1);
        return;
    }
    if(j==1)
    {
        ans.push('D');
        recon2(i-1, j);
        return;
    }

    if(dp2[i][j]==dp2[i-1][j]+a[i][j])
    {
        ans.push('D');
        recon2(i-1, j);
    }
    else
    {
        ans.push('R');
        recon2(i, j-1);
    }
}
void recon5(int i, int j)
{
    if(i==1 && j==1)
        return;

    if(i==1)
    {
        ans.push('R');
        recon5(i, j-1);
        return;
    }
    if(j==1)
    {
        ans.push('D');
        recon5(i-1, j);
        return;
    }

    if(dp5[i][j]==dp5[i-1][j]+b[i][j])
    {
        ans.push('D');
        recon5(i-1, j);
    }
    else
    {
        ans.push('R');
        recon5(i, j-1);
    }
}
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            cin>>x;
            if(!x)
            {
                zero=true;
                zeroi=i;
                zeroj=j;
            }
            else
            {
                while(x%2==0)
                {
                    a[i][j]++;
                    x/=2;
                }

                while(x%5==0)
                {
                    b[i][j]++;
                    x/=5;
                }
            }

        }

    dp2[1][1]=a[1][1];
    for(i=2; i<=n; i++)
        dp2[1][i]=dp2[1][i-1]+a[1][i];
    for(i=2; i<=n; i++)
        dp2[i][1]=dp2[i-1][1]+a[i][1];

    for(i=2; i<=n; i++)
        for(j=2; j<=n; j++)
            dp2[i][j]=a[i][j]+min(dp2[i-1][j], dp2[i][j-1]);


    dp5[1][1]=b[1][1];
    for(i=2; i<=n; i++)
        dp5[1][i]=dp5[1][i-1]+b[1][i];
    for(i=2; i<=n; i++)
        dp5[i][1]=dp5[i-1][1]+b[i][1];

    for(i=2; i<=n; i++)
        for(j=2; j<=n; j++)
            dp5[i][j]=b[i][j]+min(dp5[i-1][j], dp5[i][j-1]);

    if(min(dp2[n][n], dp5[n][n])>1 && zero)
    {
        cout<<1<<'\n';
        for(i=1; i<zeroi; i++)
            cout<<'D';
        for(i=1; i<zeroj; i++)
            cout<<'R';
        for(i=1;i<=n-zeroi;i++)
            cout<<'D';
        for(i=1;i<=n-zeroj;i++)
            cout<<'R';
        return 0;
    }

    if(dp2[n][n]<dp5[n][n])
    {
        cout<<dp2[n][n]<<'\n';
        recon2(n,n);
    }
    else
    {
        cout<<dp5[n][n]<<'\n';
        recon5(n,n);
    }

    while(!ans.empty())
    {
        cout<<ans.top();
        ans.pop();
    }
    return 0;
}
