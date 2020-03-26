#include <iostream>

using namespace std;
int n,i,v[5005];
int ans(int st, int dr, int lvl)
{
    if(st>dr)
        return 0;

    int mini=1000000000;
    int minipoz;

    for(int i=st;i<=dr;i++)
    {
        if(v[i]<=lvl)
        {
            return ans(st, i-1, lvl) + ans(i+1, dr, lvl);
        }
        if(v[i]<mini)
        {
            mini=v[i];
            minipoz=i;
        }
    }

    return min(dr-st+1, mini-lvl + ans(st, minipoz-1, mini) + ans(minipoz+1, dr, mini));
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];

    cout<<ans(1, n, 0);
    return 0;
}
