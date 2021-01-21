#include <bits/stdc++.h>

using namespace std;

int n,k,rad,i;
int st,dr,mij,last;

int query(int x)
{
    if(x<=0)
        x+=n;

    cout<<"? "<<x<<'\n';
    int ans;
    cin>>ans;
    return ans;
}
int main()
{
    cin>>n>>k;

    rad=sqrt(n)-1;

    for(i=1;i<=rad;i++)
        query(1);

    for(i=1;i<=n;i+=rad)
        if(query(i)>k)
        {
            dr=i;
            break;
        }

    st=dr-n;
    while(st<=dr)
    {
        mij=(st+dr)/2;

        if(query(mij)<=k)
        {
            last=mij;
            st=mij+1;
        }
        else
            dr=mij-1;
    }
    
    if(last<=0)
        last+=n;

    cout<<"! "<<last;
    return 0;
}
