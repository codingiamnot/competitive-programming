#include <bits/stdc++.h>

using namespace std;
int n,i,j,t;
int a[105][105];
int main()
{
    for(i=1;i<=100;i++)
    {
        a[i][i-1]=a[i][i]=a[i][i+1]=1;
    }

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cout<<a[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}
