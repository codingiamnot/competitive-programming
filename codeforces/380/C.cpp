#include <bits/stdc++.h>

using namespace std;
int n,i,m,st,dr;
string s;
struct val
{
    int len, des, inc;
    val(int len, int des, int inc)
    {
        this->len=len;
        this->des=des;
        this->inc=inc;
    }
    val() {}
    val operator+(val b)
    {
        int t=min(des, b.inc);
        val ans;
        ans.len = len + b.len + t;
        ans.des = des + b.des - t;
        ans.inc = inc + b.inc - t;
        return ans;
    }
} x;
vector <val> aib;
void upd(val x, int ti, int st, int dr, int poz)
{
    if(st==dr)
    {
        aib[poz]=x;
        return;
    }

    int mij=(st+dr)/2;

    if(mij>=ti)
        upd(x, ti, st, mij, 2*poz);
    else
        upd(x, ti, mij+1, dr, 2*poz+1);
}
void calc(int st, int dr, int poz)
{
    if(st==dr)
        return;

    int mij=(st+dr)/2;

    calc(st, mij, 2*poz);
    calc(mij+1, dr, 2*poz+1);

    aib[poz]=aib[2*poz]+aib[2*poz+1];
}
val query(int tst, int tdr, int st, int dr, int poz)
{
    if(tst==st && tdr==dr)
        return aib[poz];

    int mij=(st+dr)/2;

    if(tst>mij)
        return query(tst, tdr, mij+1, dr, 2*poz+1);

    if(tdr<=mij)
        return query(tst, tdr, st, mij, 2*poz);

    return query(tst, mij, st, mij, 2*poz) + query(mij+1, tdr, mij+1, dr, 2*poz+1);
}
int main()
{
    cin>>s;
    n=s.size();
    aib.resize(4*n+1);
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
            x=val(0, 1, 0);
        else
            x=val(0, 0, 1);

        upd(x, i, 0, n-1, 1);
    }
    calc(0, n-1, 1);

    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>st>>dr;
        x=query(st-1, dr-1, 0, n-1, 1);
        cout<<2*x.len<<'\n';
    }
    return 0;
}
