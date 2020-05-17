#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
int t,n,nr,mini,i;
bool ok1,ok2,ok3;
string s;
vector <pair<int, int>> v;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>s;
        n=s.size();
        v.clear();
        ok1=false;
        ok2=false;
        ok3=false;

        for(i=0;i<n;i++)
        {
            if(s[i]=='1')
                ok1=true;
            if(s[i]=='2')
                ok2=true;
            if(s[i]=='3')
                ok3=true;
        }

        if(!ok1 || !ok2 || !ok3)
        {
            cout<<"0\n";
            continue;
        }

        nr=1e8;
        mini=1e8;
        i=0;
        while(s[i]==s[0])
            i++;

        for(;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                if(nr!=1e8)
                    v.push_back({i-1, nr});
                nr=1;
            }
            else
            {
                nr++;
            }
        }

        mini=1e8;
        for(auto it : v)
        {
            if(s[it.f+1]!=s[it.f-it.s])
                mini=min(mini, it.s+2);
        }

        cout<<mini<<'\n';
    }
    return 0;
}
