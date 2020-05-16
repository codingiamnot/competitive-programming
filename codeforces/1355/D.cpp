#include <iostream>

using namespace std;
int n,s,i;
int main()
{
    cin>>n>>s;
    if(s>=2*n)
    {
        cout<<"YES\n";
        cout<<s-2*(n-1)<<' ';
        for(i=2;i<=n;i++)
            cout<<"2 ";
        cout<<'\n';
        cout<<1;
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
