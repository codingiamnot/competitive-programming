#include <bits/stdc++.h>

using namespace std;
int q,i,x;
string s;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>q;
    while(q)
    {
        q--;
        cin>>s;
        if(s=="sum")
        {
            long long ans=0;
            for(i=2;i<v.size();i+=5)
                ans+=v[i];
            cout<<ans<<'\n';
        }
        else
        {
            cin>>x;
            auto p=lower_bound(v.begin(), v.end(), x);

            if(s=="add")
                v.insert(p, x);
            else
                v.erase(p);
        }
    }
    return 0;
}
