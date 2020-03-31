#include <bits/stdc++.h>

using namespace std;
int t,n,i,j,x,d;
int nr;
int a[1005];
int ans[1005];
map <int, int> grup;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        nr=0;
        grup.clear();

        for(i=1;i<=n;i++)
        {
            cin>>x;
            d=2;

            while(x%d)
                d++;

            if(grup[d])
                ans[i]=grup[d];
            else
            {
                nr++;
                grup[d]=nr;
                ans[i]=grup[d];
            }
        }

        cout<<nr<<'\n';
        for(i=1;i<=n;i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
