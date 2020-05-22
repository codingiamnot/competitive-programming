#include <iostream>

using namespace std;
long long maxi,maxi2,i,n,s,a,b;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        s+=a;
    }
    for(i=1;i<=n;i++)
    {
        cin>>b;
        if(b>maxi)
        {
            maxi2=maxi;
            maxi=b;
        }
        else
            maxi2=max(maxi2, b);
    }

    if(s>maxi+maxi2)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}
