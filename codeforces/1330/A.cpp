#include <bits/stdc++.h>

using namespace std;
int t,n,x,nr,ans,var,i;
map <int, int> m;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>x;
        m.clear();
        ans=1;
        nr=0;

        for(i=1;i<=n;i++)
        {
            cin>>var;
            m[var]=1;
        }

        while(nr<=x)
        {
            if(!m[ans])
                nr++;

            if(nr>x)
                break;

            ans++;
        }

        cout<<ans-1<<'\n';
    }
    return 0;
}
