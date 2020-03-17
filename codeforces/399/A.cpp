#include <iostream>

using namespace std;
int n,p,k;
int main()
{
    cin>>n>>p>>k;
    if(max(1, p-k)!=1)
        cout<<"<< ";

    for(int i=max(1, p-k); i<=min(n, p+k);i++)
    {
        if(i==p)
            cout<<'('<<i<<')'<<' ';
        else
            cout<<i<<' ';
    }

    if(min(n, p+k)!=n)
        cout<<">>";
    return 0;
}
