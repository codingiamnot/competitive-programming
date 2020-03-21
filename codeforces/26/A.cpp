#include <bits/stdc++.h>

using namespace std;
long long nr,j,n,i,ciur[3005];
long long ans, p1, p2;
vector <int> prime;
void genciur(int maxi)
{
    for(int i=2;i<=maxi;i++)
    {
        if(!ciur[i])
        {
            prime.push_back(i);
            for(int j=i*i;j<=maxi;j+=i)
                ciur[j]=1;
        }
    }
}
int main()
{
    cin>>n;
    genciur(n);
    nr=prime.size();

    for(i=0;i<nr-1;i++)
    {
        for(j=i+1;j<nr;j++)
        {
            p1=prime[i];
            while(p1<=n)
            {
                p2=prime[j];
                while(p1*p2<=n)
                {
                    ans++;
                    p2*=prime[j];
                }
                p1*=prime[i];
            }
        }
    }
    cout<<ans;
    return 0;
}
