#include <bits/stdc++.h>

using namespace std;
int t, n, i;
long long len,sum,l,r;
void afisare(int poz, int st, int dr)
{
    //cout<<poz<<' '<<st<<' '<<dr<<'\n';
    if(i==n)
    {
        cout<<1<<' ';
        return;
    }

    for(int i=st;i<=dr;i++)
    {
        if(i%2)
            cout<<poz<<' ';
        else
            cout<<poz+i/2<<' ';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>l>>r;
        sum=0;
        for(i=1;i<=n;i++)
        {
            if(sum>=r)
                break;

            if(i==n)
                len=1;
            else
                len=2*(n-i);

            if(sum+len<l)
            {
                sum+=len;
                continue;
            }

            if(sum+len>=r)
            {
                if(sum>=l)
                    afisare(i, 1, r-sum);
                else
                    afisare(i, l-sum, r-sum);
            }

            else
            {
                if(sum>=l)
                    afisare(i, 1, 2*(n-i));
                else
                    afisare(i, l-sum, 2*(n-i));
            }

            sum+=len;
        }
        cout<<'\n';
    }
    return 0;
}
