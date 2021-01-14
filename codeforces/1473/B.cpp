#include <bits/stdc++.h>

using namespace std;

int t,nra,nrb,lmc,i;
string a,b,s1,s2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b;

        nra=a.size();
        nrb=b.size();

        lmc=nra*nrb/__gcd(nra, nrb);

        nra=lmc/nra;
        nrb=lmc/nrb;

        s1.clear();
        for(i=1;i<=nra;i++)
            s1+=a;

        s2.clear();
        for(i=1;i<=nrb;i++)
            s2+=b;

        if(s1==s2)
            cout<<s1<<'\n';
        else
            cout<<"-1\n";
    }
    return 0;
}
