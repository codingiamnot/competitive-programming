#include <bits/stdc++.h>

using namespace std;
int t,n,k,ans;
string mini,val,s;
string apply(string s, int k)
{
    string p1, p2;

    for(int i=k-1;i<n;i++)
        p1.push_back(s[i]);

    for(int i=0;i<k-1;i++)
        p2.push_back(s[i]);

    if((n-k+1)%2)
        reverse(p2.begin(), p2.end());

    return p1+p2;
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        cin>>s;
        mini=s;
        ans=1;
        for(k=2;k<=n;k++)
        {
            val=apply(s, k);
            if(val<mini)
            {
                mini=val;
                ans=k;
            }
        }
        cout<<mini<<'\n';
        cout<<ans<<'\n';
    }
    return 0;
}
