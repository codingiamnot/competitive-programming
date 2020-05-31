#include <iostream>

using namespace std;
int n,t,nrc,tg,x,y,i;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>tg;
        nrc=0;
        for(i=1;i<n;i++)
        {
            cin>>x>>y;
            if(x==tg || y==tg)
                nrc++;
        }

        if(nrc<=1)
        {
            cout<<"Ayush\n";
            continue;
        }
        if(n%2==0)
        {
            cout<<"Ayush\n";
            continue;
        }
        cout<<"Ashish\n";
    }
    return 0;
}
