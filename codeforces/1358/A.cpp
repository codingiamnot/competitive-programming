#include <iostream>

using namespace std;
long long t,n,m;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;
        cout<<(n*m+1)/2<<'\n';
    }
    return 0;
}
