#include <bits/stdc++.h>
#define mod 998244353

using namespace std;
int t,n,i,j,poz;
string s,ans,nou;
string incer(int st, int dr)
{
    string ans;
    for(int i=0;i<=st;i++)
        ans.push_back(s[i]);

    for(int i=dr;i<n;i++)
        ans.push_back(s[i]);

    return ans;
}
bool pal(string a)
{
    string b;
    b=a;
    reverse(b.begin(), b.end());
    return (a==b);
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>s;
        n=s.size();
        poz=0;
        ans.clear();
        while(s[poz]==s[n-poz-1] && 2*poz+2<=n)
            poz++;

        poz--;

        nou.clear();
        for(i=poz+1;i<n-poz-1;i++)
        {
            nou.push_back(s[i]);
            if(pal(nou) && nou.size()>ans.size())
                ans=nou;
        }

        nou.clear();
        for(i=n-poz-2;i>poz;i--)
        {
            nou.push_back(s[i]);
            if(pal(nou) && nou.size()>ans.size())
                ans=nou;
        }

        for(i=0;i<=poz;i++)
            cout<<s[i];
        cout<<ans;
        for(i=n-poz-1;i<n;i++)
            cout<<s[i];
        cout<<'\n';
    }
    return 0;
}
