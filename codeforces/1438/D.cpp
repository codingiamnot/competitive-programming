#include <bits/stdc++.h>

using namespace std;

struct pos
{
    int x, y, z;
    pos(int x, int y, int z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }
};

int n,i,sx,x;
vector<pos> ans;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        sx^=x;
    }

    if(n%2==0 && sx)
    {
        cout<<"NO";
        return 0;
    }

    for(i=3;i<=n;i+=2)
    {
        ans.push_back(pos(i-2, i-1, i));
    }

    if(n%2==0)
        n--;

    for(i=n-1;i>=2;i-=2)
    {
        ans.push_back(pos(n, i, i-1));
    }

    cout<<"YES\n";
    cout<<ans.size()<<'\n';
    for(auto it : ans)
        cout<<it.x<<' '<<it.y<<' '<<it.z<<'\n';
    return 0;
}
