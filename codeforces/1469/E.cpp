#include <bits/stdc++.h>
#define mod 2000000007

using namespace std;

int nrt,n,i,k;
char ch;
bool ok;
long long vhash,inv;
long long t[1000006];
long long v[1000006];
long long p[1000006];
set<long long> s;

bool upd()
{
    for(int i=k;i>=0;i--)
    {
        if(!i)
            return false;

        if(t[i])
        {
            t[i]=0;
            vhash-=p[k-i];
            vhash%=mod;
            if(vhash<0)
                vhash+=mod;
            break;
        }
        else
        {
            t[i]=1;
            vhash+=p[k-i];
            vhash%=mod;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    p[0]=1;
    for(i=1;i<=1e6;i++)
        p[i]=(2*p[i-1])%mod;

    inv=500000004;

    cin>>nrt;
    while(nrt)
    {
        nrt--;
        cin>>n>>k;
        s.clear();

        for(i=1;i<=n;i++)
        {
            cin>>ch;
            v[i]=ch-'0';
        }

        vhash=0;
        for(i=1;i<=k;i++)
            vhash=(vhash*2+v[i])%mod;
        s.insert(vhash);

        for(i=k+1;i<=n;i++)
        {
            vhash=(vhash*2+v[i])%mod;
            vhash-=(v[i-k]*p[k])%mod;
            vhash%=mod;
            if(vhash<0)
                vhash+=mod;

            s.insert(vhash);
        }

        /*
        for(long long it : s)
            cout<<it<<' ';
        cout<<'\n';
        */

        vhash=0;
        for(i=1;i<=k;i++)
        {
            t[i]=1;
            vhash=(2*vhash+1)%mod;
        }

        ok=false;
        while(true)
        {
            /*
            for(i=1;i<=k;i++)
                cout<<t[i];
            cout<<' '<<vhash<<'\n';
            */

            if(s.find(vhash)==s.end())
            {
                cout<<"YES\n";
                for(i=1;i<=k;i++)
                    cout<<1-t[i];
                cout<<'\n';
                ok=true;

                break;
            }

            if(!upd())
                break;
        }

        if(!ok)
            cout<<"NO\n";
    }
    return 0;
}
