#include <bits/stdc++.h>

using namespace std;
string s;
int t,n,k,i;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        cin>>s;
        sort(s.begin(), s.end());
        if(s[k-1]==s[0])
        {
            cout<<s[0];
            if(s[n-1]==s[k])
            {
                for(i=1;i<=(n-1)/k;i++)
                    cout<<s[k];
            }
            else
            {
                for(i=k;i<n;i++)
                    cout<<s[i];
            }
        }
        else
        {
            cout<<s[k-1];
        }
        cout<<'\n';
    }
    return 0;
}
