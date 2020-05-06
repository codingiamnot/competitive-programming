#include <bits/stdc++.h>

using namespace std;
int t,n,i,x,val;
bool ok;
int m[200005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        memset(m, 0, sizeof m);
        ok=true;
        for(i=0;i<n;i++)
        {
            cin>>x;
            val=(x+i)%n;
            if(val<0)
                val+=n;
            m[val]++;
        }
        for(i=0;i<n;i++)
        {
            if(m[i]!=1)
                ok=false;
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
