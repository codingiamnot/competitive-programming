#include <iostream>

using namespace std;

int t,n,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        cout<<9;
        for(i=2;i<=n;i++)
            cout<<(8+i-2)%10;
        cout<<'\n';
    }
    return 0;
}
