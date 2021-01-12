#include <bits/stdc++.h>

using namespace std;

int n,i;
int st,dr,mij,last;
int a[500005];

bool ok(int x)
{
    for(int i=1;i<=x;i++)
        if(a[i]>a[n-x+i]/2)
            return false;
    return true;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1, a+n+1);

    st=0;
    dr=n/2;

    while(st<=dr)
    {
        mij=(st+dr)/2;

        if(ok(mij))
        {
            last=mij;
            st=mij+1;
        }
        else
            dr=mij-1;
    }

    cout<<n-last;
    return 0;
}
