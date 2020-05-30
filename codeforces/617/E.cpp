#include <bits/stdc++.h>

using namespace std;
struct que
{
    int l,r,id;
    long long ans;
    que(int l, int r, int id)
    {
        this->l=l;
        this->r=r;
        this->id=id;
    }
};
int n,q,k,l,r,buc,i,x;
long long ans;
long long s[100005];
vector <que> v;
int fr[2000006];
void add(int nr)
{
    if((nr^k)<=2*1e6)
        ans+=fr[nr^k];
    fr[nr]++;
}
void del(int nr)
{
    fr[nr]--;
    if((nr^k)<=2*1e6)
        ans-=fr[nr^k];
}
bool buccmp(que a, que b)
{
    if(a.l/buc!=b.l/buc)
        return a.l/buc<b.l/buc;
    return a.r<b.r;
}
bool idcmp(que a, que b)
{
    return a.id<b.id;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q>>k;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        s[i]=s[i-1]^x;
    }
    for(i=1;i<=q;i++)
    {
        cin>>l>>r;
        v.push_back(que(l-1, r, i));
    }

    buc=sqrt(n);
    sort(v.begin(), v.end(), buccmp);

    l=1;
    r=0;
    for(auto &it : v)
    {
        while(r<it.r)
        {
            r++;
            add(s[r]);
        }
        while(r>it.r)
        {
            del(s[r]);
            r--;
        }
        while(l>it.l)
        {
            l--;
            add(s[l]);
        }
        while(l<it.l)
        {
            del(s[l]);
            l++;
        }

        it.ans=ans;
    }

    sort(v.begin(), v.end(), idcmp);
    for(auto it : v)
        cout<<it.ans<<'\n';
    return 0;
}
