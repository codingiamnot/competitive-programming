#include <bits/stdc++.h>

using namespace std;

int t,i,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>x;
        vector<int> ans;

        for(i=9;i>=1;i--)
        {
            if(x>=i)
            {
                ans.push_back(i);
                x-=i;
            }
        }

        if(x)
            cout<<"-1\n";
        else
        {
            reverse(ans.begin(), ans.end());
            for(int it : ans)
                cout<<it;
            cout<<'\n';
        }
    }
    return 0;
}
