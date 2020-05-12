#include <iostream>

using namespace std;
int t,n,i,x,k;
bool ok;
int a[100005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        for(i=1;i<=n;i++)
            a[i]=0;
        ok=false;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(x==k)
                ok=true;
            if(x>=k)
                a[i]=1;
        }

        if(!ok)
        {
            cout<<"no\n";
            continue;
        }
        ok=false;

        if(n==1)
        {
            cout<<"yes\n";
            continue;
        }

        for(i=1;i<n;i++)
            if(a[i] && a[i+1])
                ok=true;

        for(i=2;i<n;i++)
            if(a[i-1] && a[i+1])
                ok=true;

        if(ok)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
