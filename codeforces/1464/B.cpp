#include <bits/stdc++.h>

using namespace std;

long long n,i,nr0s,nr0p,nr1s,nr1p;
long long x,y,ans,ansf;
string s;
int main()
{
    cin>>s;
    cin>>x>>y;

    if(x>y)
    {
        swap(x, y);
        for(char &ch : s)
        {
            if(ch=='0')
                ch='1';
            else if(ch=='1')
                ch='0';
        }
    }

    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            nr0s++;
            ans+=nr1s*y;
        }
        else
        {
            nr1s++;
            ans+=nr0s*x;
        }
    }

    ansf=ans;

    //cout<<ans<<'\n';

    for(i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            nr0p++;
            nr0s--;
        }
        if(s[i]=='1')
        {
            nr1p++;
            nr1s--;
        }
        if(s[i]=='?')
        {
            nr1s--;

            ans-=nr0s*y;
            ans-=nr0p*x;

            ans+=nr1s*x;
            ans+=nr1p*y;

            nr0p++;
        }

        //cout<<i<<' '<<ans<<'\n';

        ansf=min(ansf, ans);
    }

    cout<<ansf;
    return 0;
}
