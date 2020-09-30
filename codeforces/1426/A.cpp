#include <bits/stdc++.h>

using namespace std;
long long t,n,x;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>x;
        if(n<=2)
        {
            cout<<"1\n";
            continue;
        }
        n-=2;
        cout<<(n+x-1)/x+1<<'\n';
    }
    return 0;
}
