#include <bits/stdc++.h>

using namespace std;
int n,m,k,i,len,x;
long long cntl,cntc,ans;
map <int, int> ml,mc;
long long cnt(map <int, int> &m , int val)
{
    long long ans=0;
    for(auto it : m)
    {
        if(it.first>=val)
            ans+=it.second*(it.first-val+1);
    }
    return ans;
}
int main()
{
    cin>>n>>m>>k;
    len=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x)
            len++;
        else
        {
            if(len)
                ml[len]++;
            len=0;
        }
    }

    if(len)
        ml[len]++;

    len=0;
    for(i=1;i<=m;i++)
    {
        cin>>x;
        if(x)
            len++;
        else
        {
            if(len)
                mc[len]++;
            len=0;
        }
    }
    if(len)
        mc[len]++;


    for(i=1;i*i<=k;i++)
    {
        if(k%i)
            continue;

        ans += cnt(ml, i)*cnt(mc, k/i);
        if(i!=k/i)
            ans += cnt(ml, k/i)*cnt(mc, i);
    }
    cout<<ans;
    return 0;
}
