#include <iostream>

using namespace std;
long long n,l,r;
long long a,b;
int main()
{
    cin>>n>>l>>r;
    a=n-l+(1<<l)-1;
    b=(n-r)*(1<<(r-1))+(1<<r)-1;
    cout<<a<<' '<<b;
    return 0;
}
