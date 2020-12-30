#include <bits/stdc++.h>

using namespace std;

int t,n,ans,i;
string s;
bool ok[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>s;
        ans=0;
        n=s.size();

        for(i=0;i<n;i++)
        {
            ok[i]=true;

            if(i>0 && s[i]==s[i-1] && ok[i-1])
            {
                ans++;
                ok[i]=false;
            }
            else if(i>1 && s[i]==s[i-2] && ok[i-2])
            {
                ans++;
                ok[i]=false;
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
