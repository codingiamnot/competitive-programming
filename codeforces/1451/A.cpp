#include <bits/stdc++.h>

using namespace std;
long long t,x,ans,i;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>x;

        if(x<=3)
        {
            cout<<x-1<<'\n';
            continue;
        }
        if(x%2==0)
        {
            cout<<"2\n";
            continue;
        }

        cout<<"3\n";
    }
    return 0;
}
