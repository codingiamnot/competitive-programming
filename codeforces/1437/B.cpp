#include <bits/stdc++.h>

using namespace std;
int n,i,ans,t;
char s[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ans=0;
        for(i=1;i<=n;i++)
        {
            cin>>s[i];
            if(i>1 && s[i]==s[i-1])
                ans++;
        }

        cout<<(ans+1)/2<<'\n';
    }
    return 0;
}
