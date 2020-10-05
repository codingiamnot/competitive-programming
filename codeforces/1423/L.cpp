#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll NMAX=1e3+5;
unordered_map<bitset<NMAX>,ll> half1,half2;
bitset<NMAX> b[31];
pair<bitset<NMAX>,ll> cpy1[1<<15];
ll szcpy1;
int main(){
    //ios_base::sync_with_stdio(false); cout.tie(0); cout.tie(0);
    ll n,s,d;
    cin>>n>>s>>d;
    for(ll i=0;i<s;i++){
        ll x,a;
        cin>>x;
        while(x--){
            cin>>a;
            b[i][a]=1;
        }
    }
    ll h1=s/3,h2=s-h1;
    for(ll i=0;i<(1<<h1);i++){
        ll cnt=0;
        bitset<NMAX> curr;
        for(ll bit=0;bit<h1;bit++){
            if(i>>bit&1){
                curr^=b[bit];
                cnt++;
            }
        }
        if(!half1.count(curr)) half1[curr]=cnt;
        else half1[curr]=min(half1[curr],cnt);
    }
    for(ll i=0;i<(1<<h2);i++){
        ll cnt=0;
        bitset<NMAX> curr;
        for(ll bit=0;bit<h2;bit++){
            if(i>>bit&1){
                curr^=b[bit+h1];
                cnt++;
            }
        }
        if(!half2.count(curr)) half2[curr]=cnt;
        else half2[curr]=min(half2[curr],cnt);
    }
    for(const auto& it : half1)
        cpy1[szcpy1++]=it;
    while(d--){
        ll x,a,ans=LLONG_MAX;
        bitset<NMAX> curr;
        cin>>x;
        while(x--){
            cin>>a;
            curr[a]=1;
        }
        for(ll j=0;j<szcpy1;j++){
            if(half2.count(cpy1[j].first^curr))
            ans=min(ans,cpy1[j].second+half2[cpy1[j].first^curr]);
        }
        cout<<(ans==LLONG_MAX?-1:ans)<<'\n';
    }
    return 0;
}
