#include <iostream>

using namespace std;
int n,i,mini;
int a[1005];
int main()
{
    cin>>n;
    mini=1e8;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        mini=min(mini, a[i]);
    }

    for(i=1;i<=n;i++)
    {
        if(a[i]%mini)
        {
            cout<<-1;
            return 0;
        }
    }

    cout<<2*n<<'\n';
    for(i=1;i<=n;i++)
        cout<<a[i]<<' '<<mini<<' ';
    return 0;
}
