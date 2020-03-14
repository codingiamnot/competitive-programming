#include <bits/stdc++.h>

using namespace std;
int t,n,x,nr,i;
map <int, bool> m;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        m.clear();
        nr=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(!m[x])
                nr++;
            m[x]=true;
        }
        cout<<nr<<'\n';
    }
    return 0;
}
