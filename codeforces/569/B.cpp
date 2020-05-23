#include <iostream>

using namespace std;
int n,poz,i,x;
int fr[100005];
int ans[100005];
int a[100005];
int main()
{
    cin>>n;
    poz=1;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {
        if(a[i]<=n && !fr[a[i]])
        {
            ans[i]=a[i];
            fr[a[i]]=1;
        }
    }

    for(i=1;i<=n;i++)
    {
        if(!ans[i])
        {
            while(fr[poz])
                poz++;
            fr[poz]=1;
            ans[i]=poz;
        }
    }

    for(i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
