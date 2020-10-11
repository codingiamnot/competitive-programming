#include <bits/stdc++.h>

using namespace std;
int t,n,i,nr,ans,p;
char s[200005];
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        v.clear();

        for(i=1;i<=n;i++)
            cin>>s[i];

        nr=0;
        for(i=1;i<=n;i++)
        {
            if(s[i]==s[i-1])
                nr++;
            else
            {
                if(nr)
                    v.push_back(nr);
                nr=1;
            }
        }
        if(nr)
            v.push_back(nr);

        reverse(v.begin(), v.end());

        p=(int)v.size()-1;
        while(p>=0 && v[p]==1)
            p--;

        ans=0;
        while(!v.empty())
        {
            if(v.back()>1)
            {
                ans++;
                v.pop_back();

                p--;
                while(p>=0 && v[p]==1)
                    p--;

                continue;
            }

            if(p==-1)
            {
                ans++;
                if(v.size()>=2)
                {
                    v.pop_back();
                    v.pop_back();
                }
                else
                    v.clear();

                continue;
            }

            ans++;
            v.pop_back();
            v[p]--;
            while(p>=0 && v[p]==1)
                p--;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
