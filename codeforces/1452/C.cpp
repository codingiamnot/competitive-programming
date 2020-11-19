#include <bits/stdc++.h>

using namespace std;
int t,nrr,nrp,ans;
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
        nrr=0;
        nrp=0;
        ans=0;

        for(char ch : s)
        {
            if(ch=='(')
                nrr++;
            if(ch=='[')
                nrp++;
            if(ch==')' && nrr)
            {
                nrr--;
                ans++;
            }
            if(ch==']' && nrp)
            {
                nrp--;
                ans++;
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
