#include <iostream>

using namespace std;
int mij,i,n,alb,negru;
bool rev;
string ans;
int main()
{
    cin>>n;
    cout<<"0 1"<<endl;
    cin>>ans;
    if(ans=="black")
        rev=true;
    n--;
    alb=0;
    negru=1e9;

    for(i=1;i<=n;i++)
    {
        mij=(alb+negru)/2;

        cout<<mij<<' '<<1<<endl;
        cin>>ans;

        if((ans=="black" && rev) || (ans=="white" && !rev))
            alb=mij;

        if((ans=="white" && rev) || (ans=="black" && !rev))
            negru=mij;
    }

    cout<<alb<<' '<<0<<' '<<negru<<' '<<2<<endl;
    return 0;
}
