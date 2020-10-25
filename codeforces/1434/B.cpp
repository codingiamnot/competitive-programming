#include <bits/stdc++.h>

using namespace std;
int n,i,nr,x;
char ch;
set<int> s,av;
vector<int> v[100005];
int ans[100005];
int main()
{
    cin>>n;
    for(i=1;i<=2*n;i++)
    {
        cin>>ch;
        if(ch=='+')
        {
            nr++;
            s.insert(nr);
        }
        else
        {
            cin>>x;
            v[nr].push_back(x);
            if(s.empty())
            {
                cout<<"NO";
                return 0;
            }

            int id=*prev(s.end());
            s.erase(id);
            ans[id]=x;
        }
    }

    for(i=1;i<=n;i++)
    {
        av.insert(ans[i]);

        for(int it : v[i])
        {
            if(av.empty())
            {
                cout<<"NO";
                return 0;
            }
            if(*av.begin() != it)
            {
                cout<<"NO";
                return 0;
            }

            av.erase(it);
        }
    }

    cout<<"YES\n";
    for(i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
