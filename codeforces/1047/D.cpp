#include <iostream>

using namespace std;
long long n,m;
int main()
{
    cin>>n>>m;
    if(n>m)
        swap(n,m);

    if(n==1)
    {
        cout<<6*(m/6)+2*max(m%6-3, (long long)0);
        return 0;
    }
    if(n==2)
    {
        if(m==2)
        {
            cout<<0;
            return 0;
        }
        if(m==3)
        {
            cout<<4;
            return 0;
        }
        if(m==7)
        {
            cout<<12;
            return 0;
        }
    }
    if(n%2==0 || m%2==0)
    {
        cout<<n*m;
        return 0;
    }
    cout<<n*m-1;
    return 0;
}
