#include <iostream>

using namespace std;
long long t,n,k;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        if(k%2!=n%2)
        {
            cout<<"NO\n";
            continue;
        }

        if(n>=k*k)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
