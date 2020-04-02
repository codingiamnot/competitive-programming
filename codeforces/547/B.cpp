#include <bits/stdc++.h>

using namespace std;
struct urs
{
    int val, l, r;
};
urs a[200005];
struct pos
{
    int i;
    pos(int i)
    {
        this->i=i;
    }
    bool operator<(pos b) const
    {
        if(a[i].val!=a[b.i].val)
            return a[i].val<a[b.i].val;
        return i<b.i;
    }
};
int n,i;
stack <int> s;
vector <int> elim[200005];
set <pos> se;
int main()
{
    cin>>n;

    for(i=1;i<=n;i++)
        cin>>a[i].val;

    s.push(0);
    for(i=1;i<=n;i++)
    {
        while(a[s.top()].val>=a[i].val)
            s.pop();

        a[i].l=s.top();
        s.push(i);
    }

    while(!s.empty())
        s.pop();

    s.push(n+1);
    for(i=n;i>=1;i--)
    {
        while(a[s.top()].val>=a[i].val)
            s.pop();

        a[i].r=s.top();
        s.push(i);
    }

    for(i=1;i<=n;i++)
        elim[a[i].r-a[i].l].push_back(i);

    for(i=1;i<=n;i++)
        se.insert(pos(i));

    for(i=1;i<=n;i++)
    {
        for(auto it : elim[i])
            se.erase(it);

        auto maxi = *(--se.end());
        int maxpoz = maxi.i;
        cout<<a[maxpoz].val<<' ';
    }
    return 0;
}
