#include <iostream>

using namespace std;
int t,i,s,x,sc,n,m;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;
        s=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(i==1)
                sc=x;
            else
                s+=x;
        }
        cout<<min(sc+s, m)<<'\n';
    }
    return 0;
}
