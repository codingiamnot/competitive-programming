#include <iostream>

using namespace std;
long long x,i;
int main()
{
    cin>>x;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            cout<<i<<x/i;
            return 0;
        }

    }
    return 0;
}
