#include <iostream>

using namespace std;
int n,i,j;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j%2==0)
                cout<<n*j+i<<' ';
            else
                cout<<n*(j+1)-i+1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
