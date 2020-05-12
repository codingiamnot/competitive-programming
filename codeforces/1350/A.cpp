#include <iostream>

using namespace std;
long long t,n,k;
long long fact(long long x)
{
    for(long long i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return i;
    }
    return x;
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        if(fact(n)!=2)
        {
            n+=fact(n);
            k--;
        }
        n+=2*k;
        cout<<n<<'\n';
    }
    return 0;
}
