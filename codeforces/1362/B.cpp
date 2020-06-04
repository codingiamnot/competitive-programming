#include <bits/stdc++.h>

using namespace std;
int t,n,maxi,i,k;
bool ok,ok2;
int a[2000];
int fr[2000],fr2[2000];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        maxi=0;
        memset(fr, 0, sizeof fr);
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            fr[a[i]]++;
            maxi=max(maxi, a[i]);
        }

        ok=false;
        for(k=1;k<=2*maxi;k++)
        {
            memset(fr2, 0, sizeof fr2);
            for(i=1;i<=n;i++)
            {
                if((a[i]^k)>maxi)
                    break;
                fr2[a[i]^k]++;
            }
            ok2=true;
            for(i=0;i<=maxi;i++)
                if(fr[i]!=fr2[i])
            {
                ok2=false;
                break;
            }

            if(ok2)
            {
                cout<<k<<'\n';
                ok=true;
                break;
            }
        }

        if(!ok)
            cout<<"-1\n";
    }
    return 0;
}
