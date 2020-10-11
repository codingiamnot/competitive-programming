#include <bits/stdc++.h>

using namespace std;
long long n,i,p,ans;
vector<int> v[40];
char s[200005];
vector<int> seg;
void upd(int stt, int drt, int st, int dr, int p)
{
    if(stt==st && drt==dr)
    {
        seg[p]++;
        return;
    }

    int mij=(st+dr)/2;
    if(drt<=mij)
    {
        upd(stt, drt, st, mij, 2*p);
        return;
    }
    if(stt>mij)
    {
        upd(stt, drt, mij+1, dr, 2*p+1);
        return;
    }
    upd(stt, mij, st, mij, 2*p);
    upd(mij+1, drt, mij+1, dr, 2*p+1);
}
int query(int i, int st, int dr, int p)
{
    if(st==dr)
        return seg[p];

    int mij=(st+dr)/2;
    if(i<=mij)
        return seg[p]+query(i, st, mij, 2*p);
    else
        return seg[p]+query(i, mij+1, dr, 2*p+1);
}
int main()
{
    cin>>n;
    seg.resize(4*n+4);
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
        v[s[i]-'a'].push_back(i);
    }
    for(i=0;i<='z'-'a';i++)
        reverse(v[i].begin(), v[i].end());

    for(i=1;i<=n;i++)
    {
        //cout<<i<<'\n';
        int p=v[s[n-i+1]-'a'].back();
        v[s[n-i+1]-'a'].pop_back();

        //cout<<p<<' '<<query(p, 1, n, 1)<<'\n';
        //cout<<p+query(p, 1, n, 1)-i<<'\n';

        ans+=p+query(p, 1, n, 1)-i;

        if(p!=1)
            upd(1, p-1, 1, n, 1);
    }

    cout<<ans;
    return 0;
}
