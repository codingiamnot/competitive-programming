#include <iostream>

using namespace std;
long long t,a,b,x,y,dif;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>x>>y;
        cin>>a>>b;
        if(x>y)
            swap(x,y);

        if(x>=0)
        {
            cout<<min(a*(x+y), b*x+a*(y-x))<<'\n';
        }
        else
        {
            if(y<=0)
            {
                cout<<min(a*(-x-y), b*(-y)+a*(y-x))<<'\n';
            }
            else
            {
                cout<<min(a*(y-x), b*(-x)+a*(y-x))<<'\n';
            }
        }
    }
    return 0;
}
