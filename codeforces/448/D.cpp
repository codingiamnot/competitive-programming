#include <iostream>

using namespace std;
long long n,m,mij,st,dr,val,k,last;
long long cnt(long long nr)
{
    long long ans=0;

    for(long long i=1;i<=n;i++)
        ans+=min((nr-1)/i, m);

    return ans;
}
int main()
{
    cin>>n>>m>>k;
    st=1;
    dr=n*m;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        val=cnt(mij);

        if(val<k)
        {
            last=mij;
            st=mij+1;
        }
        else
        {
            dr=mij-1;
        }
    }
    cout<<last;
    return 0;
}
