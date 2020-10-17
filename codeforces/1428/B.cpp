#include <bits/stdc++.h>

using namespace std;
int t,oks,okd,ans,i,n,p;
string s;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        oks=0;
        okd=0;
        cin>>n;
        cin>>s;
        for(char ch : s)
        {
            if(ch=='>')
                okd=1;
            if(ch=='<')
                oks=1;
        }

        if(oks+okd<2)
        {
            cout<<n<<'\n';
            continue;
        }

        ans=0;
        for(i=0;i<n;i++)
        {
            if(s[(i+n-1)%n]=='-' || s[i]=='-')
                ans++;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
