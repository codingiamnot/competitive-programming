#include <bits/stdc++.h>
#define LSB(i) ((i) & -(i))

using namespace std;
int n,q,x,mij,st,dr,last,i,j;
vector <long long> aib;
void add(int i, int val)
{
    while(i<=n)
    {
        aib[i]+=val;
        i+=LSB(i);
    }
}
long long sum(int i)
{
    long long sum=0;
    while(i)
    {
        sum+=aib[i];
        i-=LSB(i);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    aib.resize(n+4);
    for(i=1;i<=n;i++)
    {
        cin>>x;
        add(x, 1);
    }
    for(i=1;i<=q;i++)
    {

        cin>>x;
        if(x>0)
        {
            add(x, 1);
        }
        else
        {
            x=-x;
            st=1;
            dr=n;
            last=0;

            while(st<=dr)
            {
                mij=(st+dr)/2;
                if(sum(mij)>=x)
                {
                    last=mij;
                    dr=mij-1;
                }
                else
                {
                    st=mij+1;
                }
            }

            /*
            cout<<last<<'\n';
            for(j=1;j<=n;j++)
                cout<<sum(j)<<' ';
            cout<<'\n';
            */
            add(last, -1);
        }
    }

    for(i=1;i<=n;i++)
    {
        if(sum(i))
        {
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
