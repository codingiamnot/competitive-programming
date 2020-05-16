#include <bits/stdc++.h>

using namespace std;
long long t,n,k,mini,maxi;
void calc(long long nr)
{
    mini=10;
    maxi=0;
    while(nr)
    {
        mini=min(mini, nr%10);
        maxi=max(maxi, nr%10);
        nr/=10;
    }
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        k--;
        while(k)
        {
            calc(n);
            n+=mini*maxi;
            if(!mini)
                break;
            k--;
        }

        cout<<n<<'\n';
    }
    return 0;
}
