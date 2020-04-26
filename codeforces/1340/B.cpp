#include <iostream>

using namespace std;
int n,k,i,j,cost,cost2;
int dist[2005][15];
bool dp[2005][2005];
string mask[15];
string val[2005];
void innit()
{
    mask[0]="1110111";
    mask[1]="0010010";
    mask[2]="1011101";
    mask[3]="1011011";
    mask[4]="0111010";
    mask[5]="1101011";
    mask[6]="1101111";
    mask[7]="1010010";
    mask[8]="1111111";
    mask[9]="1111011";
}
int fcost(string a, string b)
{
    int ans=0;
    for(int i=0;i<=6;i++)
    {
        if(a[i]=='1' && b[i]=='0')
            return -1;
        if(a[i]=='0' && b[i]=='1')
            ans++;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    innit();
    for(i=1;i<=n;i++)
        cin>>val[i];

    for(i=1;i<=n;i++)
    {
        for(j=9;j>=0;j--)
        {
            dist[i][j]=fcost(val[i], mask[j]);
        }
    }

    dp[n+1][0]=true;
    for(i=n;i>=1;i--)
    {
        for(cost=0;cost<=k;cost++)
        {
            for(j=0;j<=9;j++)
            {
                cost2=dist[i][j];
                if(cost2==-1)
                    continue;
                if(cost2>cost)
                    continue;
                if(dp[i+1][cost-cost2])
                    dp[i][cost]=true;
            }
        }
    }
    if(!dp[1][k])
    {
        cout<<-1;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=9;j>=0;j--)
        {
            cost2=dist[i][j];
            if(cost2==-1)
                continue;
            if(cost2>k)
                continue;
            if(dp[i+1][k-cost2])
            {
                cout<<j;
                k-=cost2;
                break;
            }
        }
    }
    return 0;
}
