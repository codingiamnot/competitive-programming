#include <bits/stdc++.h>

using namespace std;
int t,x,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>x;

        for(i=1;i<=1e6;i++)
        {
            x-=i;
            if(x<=0)
                break;
        }

        if(x==-1)
            cout<<i+1<<'\n';
        else
            cout<<i<<'\n';
    }
    return 0;
}
