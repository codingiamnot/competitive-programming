#include <bits/stdc++.h>

using namespace std;

long long n,k,i,x,sum,ans,p;
vector<long long> v;
long long cnt[500005];
int main()
{
    cin>>n>>k;

    for(i=1;i<=n;i++)
    {
        cin>>x;
        sum+=x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    p=0;
    while(sum<0)
    {
        p++;
        if(p>k+1)
            p=1;

        cnt[p]++;
        //cout<<v.back()<<' '<<p<<'\n';
        ans+=v.back()*(cnt[p]-1);
        sum-=v.back();
        v.pop_back();
    }

    while(!v.empty())
    {
        cnt[p]++;
        //cout<<v.back()<<' '<<p<<'\n';
        ans+=v.back()*(cnt[p]-1);
        v.pop_back();
    }

    cout<<ans;
    return 0;
}
