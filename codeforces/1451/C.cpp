#include <bits/stdc++.h>

using namespace std;
int t,n,k,i;
char ch;
bool ok;
int fra[50],frb[50];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        memset(fra, 0, sizeof fra);
        memset(frb, 0, sizeof frb);

        for(i=1;i<=n;i++)
        {
            cin>>ch;
            fra[ch-'a']++;
        }
        for(i=1;i<=n;i++)
        {
            cin>>ch;
            frb[ch-'a']++;
        }

        ok=true;
        for(i=0;i<='z'-'a';i++)
        {
            if(fra[i]<frb[i])
            {
                ok=false;
                break;
            }

            if((fra[i]-frb[i])%k)
            {
                ok=false;
                break;
            }

            fra[i+1]+=fra[i]-frb[i];
        }

        if(ok)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
