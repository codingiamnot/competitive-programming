#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll NMAX=1e6+5;
ll primes[NMAX];
void erat(){
    for(ll i=4;i<NMAX;i+=2)
        primes[i]=1;
    for(ll i=3;i*i<NMAX;i+=2)
        if(!primes[i])
            for(ll j=i*i;j<NMAX;j+=i)
                primes[j]=1;
    for(ll i=1;i<NMAX;i++){
        primes[i]=primes[i-1]+(primes[i]==0);
    }
}
ll root[NMAX];
int main(){
    //ios_base::sync_with_stdio(false); cout.tie(0); cout.tie(0);
    erat();
    ll q;
    scanf("%lld",&q);
    ll curr=1;
    for(ll i=1;i<NMAX;i++){
        if(i==curr*curr)
            curr++;
        root[i]=curr-1;
    }
    for(ll i=0;i<q;i++){
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",primes[n]-primes[root[n]]+1);
    }
    return 0;
}
