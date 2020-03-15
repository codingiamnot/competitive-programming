#include <iostream>

using namespace std;
long long u,v,x;
int main()
{
    cin>>u>>v;
    if(u>v || (u%2 != v%2))
    {
        cout<<-1;
        return 0;
    }
    if(u==v)
    {
        if(u)
        {
            cout<<"1\n";
            cout<<u;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }

    x=(v-u)/2;
    if((x&u)==0)
    {
        cout<<"2\n";
        cout<<u+x<<' '<<x;
        return 0;
    }
    cout<<"3\n";
    cout<<u<<' '<<x<<' '<<x;
    return 0;
}
