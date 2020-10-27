#include <bits/stdc++.h>

using namespace std;
int nrt,n,i,ans,last,nr,cnt;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>nrt;
    while(nrt)
    {
        nrt--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>v[i];

        ans=1;
        last=1;
        nr=1;
        cnt=1;

        for(i=3;i<=n;i++)
        {
            if(v[i]<v[i-1])
            {
                if(nr==last)
                {
                    ans++;
                    last=cnt;
                    nr=1;
                    cnt=1;
                }
                else
                {
                    nr++;
                    cnt++;
                }
            }
            else
                cnt++;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
