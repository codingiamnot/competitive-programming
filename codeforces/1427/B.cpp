#include <bits/stdc++.h>

using namespace std;
int t,n,k,i,ans,nr,nr1;
bool ok;
char v[100005];
vector<int> dif;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        ans=0;
        dif.clear();
        ok=false;
        nr=0;
        nr1=0;

        for(i=1;i<=n;i++)
        {
            cin>>v[i];
            if(v[i]=='W')
            {
                nr1++;
                if(nr && ok)
                    dif.push_back(nr);
                nr=0;
                ok=true;

                ans++;
                if(v[i-1]=='W')
                    ans++;
            }
            else
                nr++;
        }


        if(!nr1)
        {
            cout<<max(0, min(n*2-1, k*2-1))<<'\n';
            continue;
        }

        k=min(k, n-nr1);
        ans+=2*k;

        if(!dif.empty())
        {
            sort(dif.begin(), dif.end());
            for(int it : dif)
            {
                if(it<=k)
                {
                    ans++;
                    k-=it;
                }
                else
                    break;
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
