#include <bits/stdc++.h>

using namespace std;
struct nod
{
    int mini=0,maxi=0,sum=0;
    nod(int val)
    {
        this->mini=val;
        this->maxi=val;
        this->sum=val;
    }
    nod(){}
    nod operator+(nod b)
    {
        nod ans;
        ans.sum=sum+b.sum;
        ans.mini=min(mini, sum+b.mini);
        ans.maxi=max(maxi, sum+b.maxi);
        return ans;
    }
};
int n,p,i;
char ch;
vector <nod> seg;
void upd(int i, int val, int st, int dr, int poz)
{
    if(st==dr)
    {
        seg[poz]=nod(val);
        return;
    }

    int mij=(st+dr)/2;

    if(i<=mij)
        upd(i, val, st, mij, 2*poz);
    else
        upd(i, val, mij+1, dr, 2*poz+1);

    seg[poz]=seg[2*poz]+seg[2*poz+1];
}
int ans(nod a)
{
    if(a.sum || a.mini<0)
        return -1;
    return a.maxi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    seg.resize(4*n+4);
    p=1;

    for(i=1;i<=n;i++)
    {
        cin>>ch;
        if(ch=='L' && p!=1)
        {
            p--;
        }
        if(ch=='R')
            p++;
        if(ch=='(')
            upd(p, 1, 1, n, 1);
        if(ch==')')
            upd(p, -1, 1, n, 1);
        if(ch>='a' && ch<='z')
            upd(p, 0, 1, n, 1);

        cout<<ans(seg[1])<<' ';
    }
    return 0;
}
