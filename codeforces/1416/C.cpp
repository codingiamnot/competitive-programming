#include <bits/stdc++.h>

using namespace std;
struct pos
{
    vector<int> *v;
    int b;
    pos(vector<int> *v, int b)
    {
        this->v=v;
        this->b=b;
    }
};
long long n,x,ans0,ans1,i,ans;
queue<pos> q;
void inv(vector<int> &a, int b)
{
    if(b==-1)
        return;
    if(a.empty())
        return;

    /*
    cout<<b<<'\n';
    for(int it : a)
        cout<<it<<' ';
    cout<<'\n';
    */

    int nr0,nr1;
    nr0=nr1=0;
    vector<int> *v0, *v1;
    v0=new vector<int>();
    v1=new vector<int>();
    for(int it : a)
    {
        int v=(it>>b)&1;

        if(v)
        {
            ans1+=nr0;
            nr1++;
            v1->push_back(it);
        }
        else
        {
            ans0+=nr1;
            nr0++;
            v0->push_back(it);
        }
    }

    q.push(pos(v0, b-1));
    q.push(pos(v1, b-1));
}
int main()
{
    cin>>n;
    vector<int> a;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }

    const int maxb=29;
    q.push(pos(&a, maxb));

    x=0;
    for(int b=maxb;b>=0;b--)
    {
        ans0=ans1=0;
        while(q.front().b==b)
        {
            inv(*q.front().v, q.front().b);
            q.pop();
        }

        //cout<<b<<' '<<ans0<<' '<<ans1<<'\n';
        if(ans1<ans0)
        {
            x+=(1<<b);
            ans+=ans1;
        }
        else
            ans+=ans0;
    }

    cout<<ans<<' '<<x;
    return 0;
}
