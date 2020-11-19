#include <bits/stdc++.h>

using namespace std;
long long t,x,sum,maxi,n,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        maxi=0;
        sum=0;

        for(i=1;i<=n;i++)
        {
            cin>>x;
            maxi=max(maxi, x);
            sum+=x;
        }

        if(maxi*(n-1)>=sum)
        {
            cout<<maxi*(n-1)-sum<<'\n';
        }
        else
        {
            cout<<((n-1)-(sum%(n-1)))%(n-1)<<'\n';
        }
    }
    return 0;
}
