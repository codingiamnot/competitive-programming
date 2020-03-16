#include <bits/stdc++.h>

using namespace std;
int n,i,j,ans;
map <int, int> m;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        m.clear();
        for(j=0;j+i<=n;j++)
        {
            m[j%i]++;
            if(m[j%i]==1)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
