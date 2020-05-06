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
        if(n>m)
            swap(n,m);

        if(n==1)
        {
            cout<<"Yes\n";
        }
        if(n==2)
        {
            if(m==2)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        if(n>2)
            cout<<"No\n";
    }
    return 0;
}
