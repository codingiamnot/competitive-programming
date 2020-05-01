#include <bits/stdc++.h>

using namespace std;
int t,n,i,x,k;
set<int> s;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        s.clear();
        for(i=1;i<=n;i++)
        {
            cin>>x;
            s.insert(x);
        }

        if(s.size()>k)
        {
            cout<<"-1\n";
            continue;
        }

        cout<<n*k<<'\n';
        for(i=1;i<=n;i++)
        {
            for(int it : s)
                cout<<it<<' ';

            for(int j=s.size()+1;j<=k;j++)
                cout<<1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
