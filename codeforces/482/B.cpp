#include <bits/stdc++.h>

using namespace std;
struct que
{
    int st, dr;
    long long val;
    que(int st, int dr, long long val)
    {
        this->st=st;
        this->dr=dr;
        this->val=val;
    }
};
int n,m,i,b,sum;
int st,dr;
long long val,ans;
int smen[35][100005];
int s[35][100005];
vector <que> q;
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>st>>dr>>val;
        q.push_back(que(st, dr, val));
        for(b=0;b<=29;b++)
        {
            if((val>>b)&1)
            {
                smen[b][st]++;
                smen[b][dr+1]--;
            }
        }
    }

    for(b=0;b<=29;b++)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=smen[b][i];
            if(sum>0)
                val=1;
            else
                val=0;

            s[b][i]=s[b][i-1]+val;
        }
    }

    for(que it : q)
    {
        for(b=0;b<=29;b++)
        {
            if(!((it.val>>b)&1))
            {
                if(s[b][it.dr]-s[b][it.st-1]==it.dr-it.st+1)
                {
                    cout<<"NO";
                    return 0;
                }
            }
        }
    }

    cout<<"YES\n";
    for(i=1;i<=n;i++)
    {
        ans=0;
        for(b=0;b<=29;b++)
        {
            if(s[b][i]>s[b][i-1])
                ans+=(1<<b);
        }
        cout<<ans<<' ';
    }
    return 0;
}
