#include <iostream>

using namespace std;
long long t,n,a,b,c,d;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>a>>b>>c>>d;
        if(n*(a+b)<c-d || n*(a-b)>c+d)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}
