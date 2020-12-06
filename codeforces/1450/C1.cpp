#include <bits/stdc++.h>

using namespace std;

int t,n,i,j,nr;
char a[305][305];
int fr[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        memset(fr, 0, sizeof fr);

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='X')
                    fr[(i+j)%3]++;
            }

        if(fr[0]<=min(fr[1], fr[2]))
            nr=0;
        if(fr[1]<=min(fr[0], fr[2]))
            nr=1;
        if(fr[2]<=min(fr[0], fr[1]))
            nr=2;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i][j]=='X' && (i+j)%3==nr)
                    cout<<'O';
                else
                    cout<<a[i][j];
            }
            cout<<'\n';
        }
    }
    return 0;
}
