#include <iostream>

using namespace std;
long long t,x,n,m;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>x>>n>>m;
        while(x)
        {
            if(!n)
            {
                x-=m*10;
                break;
            }
            else
            {
                if(x/2+10>=x)
                {
                    x-=m*10;
                    break;
                }
                x=x/2+10;
                n--;
            }
        }

        if(x>0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
