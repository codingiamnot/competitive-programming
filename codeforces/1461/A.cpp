#include <iostream>

using namespace std;

int t,n,k,i;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cout<<(char)('a'+(i%3));
        }
        cout<<'\n';
    }
    return 0;
}
