#include <bits/stdc++.h>

using namespace std;

int t,n,k,nr,i;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        nr=n-k+1;

        for(i=1;i<=k-nr;i++)
            cout<<i<<' ';
        for(i=1;i<=nr;i++)
            cout<<k-i+1<<' ';
        cout<<'\n';
    }
    return 0;
}
