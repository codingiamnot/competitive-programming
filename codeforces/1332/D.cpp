#include <iostream>

using namespace std;
long long k,val,sum;
int main()
{
    cin>>k;
    val=1;
    while(val<=k)
    {
        sum+=val;
        val*=2;
    }
    sum+=val;

    cout<<"3 3\n";
    cout<<sum<<' '<<sum<<' '<<val<<'\n';
    cout<<sum<<' '<<k<<' '<<sum<<'\n';
    cout<<val<<' '<<sum<<' '<<k<<'\n';
    return 0;
}
