#include <iostream>

using namespace std;

int t,n,i;
int a[3005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=1;i<=n;i++)
        {
            if(i%2)
                cout<<a[i/2+1]<<' ';
            else
                cout<<a[n-i/2+1]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
