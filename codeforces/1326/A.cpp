#include <iostream>

using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        if(n==1)
        {
            cout<<"-1\n";
            continue;
        }
        if((n-1)%3)
        {
            for(int i=1;i<n;i++)
                cout<<2;
            cout<<3;
        }
        else
        {
            for(int i=1;i<n-1;i++)
                cout<<2;
            cout<<"33";
        }
        cout<<'\n';
    }
    return 0;
}
