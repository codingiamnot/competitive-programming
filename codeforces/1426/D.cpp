#include <bits/stdc++.h>

using namespace std;
long long n,sum,x,i,ans;
map<long long, long long> fr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    fr[0]=1;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        sum+=x;

        if(fr[sum])
        {
            fr.clear();
            fr[0]=1;
            sum=x;
            ans++;
        }

        fr[sum]++;
    }

    cout<<ans;
    return 0;
}
