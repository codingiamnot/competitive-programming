#include <bits/stdc++.h>
#define mod 998244353
#define baza 29

using namespace std;
int t,n,i,j,poz,n2,ans1,ans2;
long long h1,h2,put;
string s,s2;
bool pal(string a)
{
    string b;
    b=a;
    reverse(b.begin(), b.end());
    return (a==b);
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        s.clear();
        s2.clear();
        ans1=0;
        ans2=0;
        poz=0;
        cin>>s;
        n=s.size();
        while(s[poz]==s[n-poz-1] && 2*poz+2<=n)
            poz++;

        poz--;

        for(i=poz+1; i<n-poz-1; i++)
            s2.push_back(s[i]);

        n2=s2.size();

        if(n2)
        {
            h1=0;
            h2=0;
            put=1;

            for(i=0; i<n2; i++)
            {
                h1*=baza;
                h1%=mod;
                h1+=s2[i]-'a';
                h1%=mod;

                h2+=(s2[i]-'a')*put;
                h2%=mod;
                put*=baza;
                put%=mod;


                if(h1==h2)
                    ans1=i;
            }

            h1=0;
            h2=0;
            put=1;

            for(i=n2-1; i>=0; i--)
            {
                h1*=baza;
                h1%=mod;
                h1+=s2[i]-'a';
                h1%=mod;

                h2+=(s2[i]-'a')*put;
                h2%=mod;
                put*=baza;
                put%=mod;


                if(h1==h2)
                    ans2=i;
            }
        }

        for(i=0; i<=poz; i++)
            cout<<s[i];

        if(n2)
        {
            if(ans1+1>n2-ans2)
            {
                for(i=0; i<=ans1; i++)
                    cout<<s2[i];
            }
            else
            {
                for(i=ans2; i<n2; i++)
                    cout<<s2[i];
            }
        }

        for(i=n-poz-1; i<n; i++)
            cout<<s[i];

        cout<<'\n';
    }
    return 0;
}
