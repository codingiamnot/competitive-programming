#include <iostream>

using namespace std;
int i,t,n,last,ans;
string s;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>s;
        n=s.size();
        s[n]='R';
        last=-1;
        ans=0;
        for(i=0;i<=n;i++)
        {
            if(s[i]=='R')
            {
                ans=max(ans, i-last);
                last=i;
            }

        }

        cout<<ans<<'\n';
    }
    return 0;
}
