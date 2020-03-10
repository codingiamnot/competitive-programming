#include <iostream>

using namespace std;
int t,a,b;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b;
        if(a%b==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
