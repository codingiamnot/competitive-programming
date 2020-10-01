#include <bits/stdc++.h>

using namespace std;
int t,n,i,nr,k;
int a[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        nr=0;
        a[0]=-1;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]!=a[i-1])
                nr++;
        }

        if(k>=nr)
        {
            cout<<"1\n";
            continue;
        }
        if(k==1)
        {
            cout<<"-1\n";
            continue;
        }

        cout<<(nr-2)/(k-1)+1<<'\n';
    }
    return 0;
}
