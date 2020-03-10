#include <bits/stdc++.h>

using namespace std;
long long x,i,t,n,k,b,fr[65];
bool ok;
void calc(long long x)
{
    int b=-1;

    while(x)
    {
        fr[++b]+=x%k;
        x/=k;
    }
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        ok=true;
        for(b=0; b<=60; b++)
            fr[b]=0;
        cin>>n>>k;
        for(i=1; i<=n; i++)
        {
            cin>>x;
            calc(x);
        }

        for(b=0; b<=60; b++)
            if(fr[b]>1)
            {
                cout<<"NO\n";
                ok=false;
                break;
            }

        if(ok)
            cout<<"Yes\n";
    }
    return 0;
}
