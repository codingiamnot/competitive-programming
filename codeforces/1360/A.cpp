#include <iostream>

using namespace std;
long long a,b,l,t;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        l=max(2*a, b);
        cout<<l*l<<'\n';
    }
    return 0;
}
