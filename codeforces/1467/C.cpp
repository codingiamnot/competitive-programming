#include <iostream>

using namespace std;

long long s1,s2,s3,min1,min2,min3,n1,n2,n3;
long long i,x,ans;
int main()
{
    min1=min2=min3=1e9;

    cin>>n1>>n2>>n3;

    for(i=1;i<=n1;i++)
    {
        cin>>x;
        s1+=x;
        min1=min(min1, x);
    }

    for(i=1;i<=n2;i++)
    {
        cin>>x;
        s2+=x;
        min2=min(min2, x);
    }

    for(i=1;i<=n3;i++)
    {
        cin>>x;
        s3+=x;
        min3=min(min3, x);
    }

    ans=0;
    ans=max(ans, s1+s2-s3);
    ans=max(ans, s1-s2+s3);
    ans=max(ans, -s1+s2+s3);
    ans=max(ans, s1+s2+s3-2*min1-2*min2);
    ans=max(ans, s1+s2+s3-2*min1-2*min3);
    ans=max(ans, s1+s2+s3-2*min2-2*min3);

    cout<<ans;
    return 0;
}
