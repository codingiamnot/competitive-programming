#include <bits/stdc++.h>

using namespace std;
long long n,a,r,m,i,ans,lo,hi,mij1,mij2;
long long v[100005];
long long s[100005];

long long cost(long long H) {
	int pos = lower_bound(v+1, v+n+1, H) - v;
	long long res = 0;
	long long k1 = H * (pos-1) - s[pos-1];
	long long k2 = s[n] - s[pos-1] - H * (n - pos + 1);
	res = min(k1, k2);
	k1 -= res;
	k2 -= res;
	res *= m;
	res += k1 * a;
	res += k2 * r;
	return res;
}
int main()
{
    cin>>n>>a>>r>>m;
    m=min(m, a+r);
    for(i=1;i<=n;i++)
        cin>>v[i];

    sort(v+1, v+n+1);

    for(i=1;i<=n;i++)
        s[i]=s[i-1]+v[i];

    ans=1e18;

    lo=v[1];
    hi=v[n];

    while(hi-lo>1e2)
    {
        mij1 = lo + (hi-lo)/3;
        mij2 = hi - (hi-lo)/3;

        if(cost(mij1)<cost(mij2))
            hi=mij2;
        else
            lo=mij1;
    }

    ans=1e18;
    for(i=lo;i<=hi;i++)
        ans=min(ans, cost(i));

    cout<<ans;
    return 0;
}
