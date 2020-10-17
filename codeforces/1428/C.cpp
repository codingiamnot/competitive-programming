#include <bits/stdc++.h>

using namespace std;
int t,nr,nrb,ans;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t)
    {
        t--;
        cin>>s;
        nr=0;
        nrb=0;
        ans=0;
        for(char ch : s)
        {
            if(ch=='A')
                nr++;
            else
            {
                if(nr)
                {
                    nr--;
                    ans+=2;
                }
                else
                    nrb++;
            }
        }

        ans+=(nrb/2)*2;
        cout<<(int)s.size()-ans<<'\n';
    }
    return 0;
}
