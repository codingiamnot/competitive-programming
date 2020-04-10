#include <bits/stdc++.h>

using namespace std;
struct valS
{
    int cmmdc, mini, fr;
    valS(){}
    valS(int nr)
    {
        this->mini=nr;
        this->cmmdc=nr;
        this->fr=1;
    }
    valS operator+(valS b)
    {
        valS ans;
        ans.cmmdc = __gcd(cmmdc, b.cmmdc);
        ans.mini = min(mini, b.mini);
        ans.fr=0;

        if(mini==ans.mini)
            ans.fr+=fr;
        if(b.mini==ans.mini)
            ans.fr+=b.fr;

        return ans;
    }
};
int n,q;
int i,x,st,dr;
valS ans;
vector <valS> aib;
void upd(int i, valS x, int st, int dr, int poz)
{
    if(st==dr)
    {
        aib[poz]=x;
        return;
    }

    int mij = (st+dr)/2;

    if(i<=mij)
        upd(i, x, st, mij, 2*poz);
    else
        upd(i, x, mij+1, dr, 2*poz+1);
}
void calc(int st, int dr, int poz)
{
    if(st==dr)
        return;

    int mij = (st+dr)/2;

    calc(st, mij, 2*poz);
    calc(mij+1, dr, 2*poz+1);

    aib[poz]=aib[2*poz]+aib[2*poz+1];
}
valS query(int stt, int drt, int st, int dr, int poz)
{
    if(stt==st && drt==dr)
        return aib[poz];

    int mij = (st+dr)/2;

    if(drt<=mij)
        return query(stt, drt, st, mij, 2*poz);
    if(stt>mij)
        return query(stt, drt, mij+1, dr, 2*poz+1);

    return query(stt, mij, st, mij, 2*poz) + query(mij+1, drt, mij+1, dr, 2*poz+1);
}
int main()
{
    cin>>n;
    aib.resize(4*n+5);
    for(i=1;i<=n;i++)
    {
        cin>>x;
        upd(i, valS(x), 1, n, 1);
    }

    calc(1, n, 1);

    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>st>>dr;
        ans = query(st, dr, 1, n, 1);

        if(ans.cmmdc==ans.mini)
            cout<<dr-st+1-ans.fr<<'\n';
        else
            cout<<dr-st+1<<'\n';
    }
    return 0;
}
