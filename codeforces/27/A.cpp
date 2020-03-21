#include <iostream>
#include <algorithm>

using namespace std;
int n,i,a[3005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1, a+n+1);

    for(i=1;i<=n;i++)
    {
        if(a[i]!=i)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<n+1;
    return 0;
}
