#include <iostream>

using namespace std;
long long A,B,C,D,ans,i;
long long calc(long long x, long long y, long long x2, long long y2)
{
    long long ans=0;
    if(x>y2)
        return (y-x+1)*(y2-x2+1);

    x=max(x, x2);

    if(y>y2)
    {
        ans+=(y-y2)*(y2-x2+1);
        y=y2;
    }

    ans+=(y-x2)*(y-x2+1)/2;
    ans-=(x-x2-1)*(x-x2)/2;

    return ans;
}
int main()
{
    //cout<<calc(2, 3, 1, 3);
    //return 0;
    cin>>A>>B>>C>>D;
    for(i=A;i<=B;i++)
    {
        ans+=calc(B+i, C+i, C, D);
    }

    cout<<ans;
    return 0;
}
