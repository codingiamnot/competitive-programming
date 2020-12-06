#include <bits/stdc++.h>

using namespace std;

int t,nr,i,n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        cin>>s;
        nr=0;
        for(char ch : s)
            if(ch=='b')
                nr++;

        for(i=1;i<=nr;i++)
            cout<<'b';
        for(char ch : s)
        {
            if(ch=='b')
                continue;
            cout<<ch;
        }

        cout<<'\n';
    }
    return 0;
}
