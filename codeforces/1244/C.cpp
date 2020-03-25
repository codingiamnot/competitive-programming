#include <iostream>

using namespace std;
long long n,p,w,d,x,y;
int main()
{
    cin>>n>>p>>w>>d;
    for(y=0;y<w;y++)
    {
        if(y*d>p)
            break;
        if((p-y*d)%w==0)
        {
            x=(p-y*d)/w;

            if(x+y<=n)
            {
                cout<<x<<' '<<y<<' '<<n-x-y;
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}
