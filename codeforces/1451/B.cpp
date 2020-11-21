#include <bits/stdc++.h>

using namespace std;
int n,i,p,l,r,q,t;
bool ok;
char ch[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>q;
        for(i=1;i<=n;i++)
            cin>>ch[i];

        while(q)
        {
            q--;
            cin>>l>>r;

            ok=false;

            for(i=1;i<l;i++)
                if(ch[i]==ch[l])
                    ok=true;

            for(i=r+1;i<=n;i++)
                if(ch[i]==ch[r])
                    ok=true;

            if(ok)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
