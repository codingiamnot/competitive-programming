#include <bits/stdc++.h>

using namespace std;

int t,n,i,j,nrx,nro,k;
char a[305][305];
int frx[10];
int fro[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        k=0;
        memset(frx, 0, sizeof frx);
        memset(fro, 0, sizeof fro);

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='X')
                {
                    frx[(i+j)%3]++;
                    k++;
                }
                if(a[i][j]=='O')
                {
                    fro[(i+j)%3]++;
                    k++;
                }

            }

        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i==j)
                    continue;

                if(frx[i]+fro[j]<=k/3)
                {
                    nrx=i;
                    nro=j;
                }
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i][j]=='X' && (i+j)%3==nrx)
                    a[i][j]='O';
                if(a[i][j]=='O' && (i+j)%3==nro)
                    a[i][j]='X';

                cout<<a[i][j];
            }
            cout<<'\n';
        }
    }
    return 0;
}
