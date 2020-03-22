#include <bits/stdc++.h>

using namespace std;
long long n,i,j,l,k;
long long drum[505][505];
long long ans[505];
int v[505];
bool exista[505];
void floyd(int nou)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(drum[i][nou]+drum[nou][j] < drum[i][j])
                drum[i][j]=drum[i][nou]+drum[nou][j];
        }
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>drum[i][j];

    for(i=1;i<=n;i++)
        cin>>v[i];


    for(l=n;l>=1;l--)
    {
        exista[v[l]]=true;
        k=v[l];

        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(drum[i][k]+drum[k][j]<drum[i][j] && i!=j)
                {
                    drum[i][j]=drum[i][k]+drum[k][j];
                }

                if(exista[i] && exista[j])
                    ans[l]+=drum[i][j];
            }
        }
    }

    for(i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
