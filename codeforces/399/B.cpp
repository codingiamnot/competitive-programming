#include <iostream>

using namespace std;
int n,i;
long long ans,b[55];
char ch;
int main()
{
    cin>>n;
    b[1]=1;
    for(i=2;i<=n;i++)
    {
        b[i]=2*b[i-1]+1;
    }
    for(i=1;i<=n;i++)
    {
        cin>>ch;
        if(ch=='B')
            ans+=1+b[i-1];
    }
    cout<<ans;
    return 0;
}
