#include <iostream>

using namespace std;

int query(int t, int i, int j)
{
    if(t==1)
        cout<<"AND ";
    if(t==2)
        cout<<"OR ";
    if(t==3)
        cout<<"XOR ";

    cout<<i<<' '<<j<<'\n';

    int ans;
    cin>>ans;
    return ans;
}

int n,i,sum;
int x12,x13,x23;
int a12,a13,a23;
int s12,s13,s23;
int ans[100005];
int main()
{
    cin>>n;

    x12=query(3, 1, 2);
    x13=query(3, 1, 3);
    x23=x12^x13;

    a12=query(1, 1, 2);
    a13=query(1, 1, 3);
    a23=query(1, 2, 3);

    s12=x12+2*a12;
    s13=x13+2*a13;
    s23=x23+2*a23;

    sum=(s12+s13+s23)/2;

    ans[1]=sum-s23;
    ans[2]=sum-s13;
    ans[3]=sum-s12;

    for(i=4;i<=n;i++)
        ans[i]=ans[1]^query(3, 1, i);


    cout<<"! ";
    for(i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
