#include <iostream>

using namespace std;
long long n3,n7,n,t,i;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        n3=0;
        while(n3*(n3+1)<=2*n)
            n3++;

        n7=n-n3*(n3-1)/2;
        cout<<1;
        cout<<33;
        for(i=1;i<=n7;i++)
            cout<<7;
        for(i=3;i<=n3;i++)
            cout<<3;
        cout<<7;
        cout<<'\n';
    }
    return 0;
}
