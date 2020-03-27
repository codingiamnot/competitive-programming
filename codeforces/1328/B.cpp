#include <bits/stdc++.h>

using namespace std;
long long t,n,k,i,bef;
string ans;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        ans.clear();
        bef=0;

        cin>>n>>k;
        for(i=1; i<=n; i++)
            ans.push_back('a');

        for(i=n-1; i>=1; i--)
        {
            if(bef+n-i>=k)
            {
                ans[i-1]='b';
                ans[n-k+bef]='b';
                cout<<ans<<'\n';
                break;
            }
            bef+=n-i;
        }
    }

    return 0;
}
