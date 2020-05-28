#include <iostream>

using namespace std;
long long t,n,m,k;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m>>k;
        if(n/k>=m)
            cout<<m<<'\n';
        else
        {
            cout<<n/k-(m-n/k+k-2)/(k-1)<<'\n';
        }
    }
    return 0;
}
