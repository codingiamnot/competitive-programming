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
            cout<<"0\n";
        else
            cout<<b-a%b<<'\n';
    }
    return 0;
}
