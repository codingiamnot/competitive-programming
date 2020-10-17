#include <bits/stdc++.h>

using namespace std;
struct pos
{
    int id;
    long long val;
    pos(int id, long long val)
    {
        this->id=id;
        this->val=val;
    }
    bool operator<(pos b) const
    {
        return val<b.val;
    }
};
long long n,k,i,ans;
long long a[100005];
long long nr[100005];
multiset<pos> s;
long long f(long long val, long long nr)
{
    nr++;
    long long h=val/nr;
    long long cnt1=val%nr;

    long long ans=(h+1)*(h+1)*cnt1 + h*h*(nr-cnt1);
    return ans;
}
void add(int i)
{
    long long del=f(a[i], nr[i]+1)-f(a[i], nr[i]);
    s.insert(pos(i, del));
}
int main()
{
    cin>>n>>k;
    k=k-n;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=a[i]*a[i];
        nr[i]=0;

        add(i);
    }

    while(k)
    {
        /*
        for(auto it : s)
            cout<<it.id<<' '<<it.val<<'\n';
        cout<<'\n';
        */

        k--;
        auto it=*s.begin();
        s.erase(s.begin());

        ans+=it.val;
        nr[it.id]++;
        add(it.id);
    }

    cout<<ans;
    return 0;
}
