#include <iostream>

using namespace std;
int x, y, x1,y1, x2,y2, t,l,r,u,d;
bool apar(int x, int y)
{
    return (x>=x1 && x<=x2 && y>=y1 && y<=y2);
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>l>>r>>d>>u;
        cin>>x>>y>>x1>>y1>>x2>>y2;

        if(x1==x2 && (r!=0 || l!=0))
        {
            cout<<"No\n";
            continue;
        }

        if(y1==y2 && (u!=0 || d!=0))
        {
            cout<<"No\n";
            continue;
        }

        u-=d;
        r-=l;
        if(apar(x, y) && apar(x+r, y+u))
        {
            cout<<"Yes\n";
            continue;
        }

        else
            cout<<"No\n";
    }
    return 0;
}
