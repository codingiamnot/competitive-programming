#include <bits/stdc++.h>

using namespace std;
long long t,a,b,c,x,y,z;
long long cost,ans,ansx,ansy,ansz;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b>>c;
        ans=1000000;
        for(x=1;x<=100000;x++)
        {
            for(y=x;y<=100000;y+=x)
            {
                z=c;
                if(z%y<y-z%y)
                    z-=z%y;
                else
                    z+=y-z%y;

                cost=abs(a-x)+abs(b-y)+abs(c-z);
                if(cost<ans)
                {
                    ans=cost;
                    ansx=x;
                    ansy=y;
                    ansz=z;
                }
            }
        }

        cout<<ans<<'\n';
        cout<<ansx<<' '<<ansy<<' '<<ansz<<'\n';
    }
    return 0;
}
