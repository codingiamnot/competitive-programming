#include <bits/stdc++.h>

using namespace std;
int t,n,i,x;
bool ok;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        m.clear();
        ok=false;

        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(m[x]>0)
                ok=true;
            m[x]++;
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
