#include <bits/stdc++.h>

using namespace std;
struct pos
{
    long long x, y;
    vector<int> *p, *m;

    pos(){}
    pos(long long x, long long y, int i)
    {
        this->x=x;
        this->y=y;
        p=new vector<int>();
        m=new vector<int>();
        p->push_back(i);
    }
};

int n,i;
long long x,y;
int ans[100005];
deque<pos> q;
pos temp, rez;

bool ok(long long x, long long y, long long xp, long long yp)
{
    long long sz=(x+xp)*(x+xp)+(y+yp)*(y+yp);
    return sz<=1e12;
}
bool okf(pos a, pos b)
{
    if(ok(a.x, a.y, b.x, b.y))
        return true;
    if(ok(a.x, a.y, -b.x, -b.y))
        return true;
    return false;
}
pos mergef(pos a, pos b)
{
    if(a.p->size()+a.m->size() < b.p->size()+b.m->size())
        swap(a, b);

    pos ans=a;

    if(ok(a.x, a.y, b.x, b.y))
    {
        ans.x+=b.x;
        ans.y+=b.y;

        for(int it : *b.p)
            a.p->push_back(it);
        for(int it : *b.m)
            a.m->push_back(it);
    }
    else
    {
        ans.x-=b.x;
        ans.y-=b.y;

        for(int it : *b.m)
            a.p->push_back(it);
        for(int it : *b.p)
            a.m->push_back(it);
    }

    return ans;
}
void repr(pos a)
{
    cout<<a.x<<' '<<a.y<<'\n';
    for(int it : *a.p)
        cout<<it<<' ';
    cout<<'\n';
    for(int it : *a.m)
        cout<<it<<' ';
    cout<<'\n';
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        q.push_back(pos(x, y, i));
    }

    if(n==1)
    {
        cout<<1;
        return 0;
    }

    while(q.size()>2)
    {
        if(okf(q[0], q[1]))
        {
            temp=q[2];
            q.push_back(mergef(q[0], q[1]));
        }
        else if(okf(q[0], q[2]))
        {
            temp=q[1];
            q.push_back(mergef(q[0], q[2]));
        }
        else
        {
            temp=q[0];
            q.push_back(mergef(q[1], q[2]));
        }

        q.pop_front();
        q.pop_front();
        q.pop_front();
        q.push_front(temp);

        /*
        cout<<'\n';
        for(auto it : q)
        {
            repr(it);
        }
        cout<<'\n';
        */
    }

    rez=mergef(q[0], q[1]);

    for(int it : *rez.p)
        ans[it]=1;

    for(int it : *rez.m)
        ans[it]=-1;

    for(i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
