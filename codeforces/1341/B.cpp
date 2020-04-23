#include <iostream>

using namespace std;
int t,n,k,i,j,nmaxi,maxi,imaxi;
int a[200005];
int s[200005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        maxi=0;
        imaxi=1;
        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=2;i<n;i++)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1])
                s[i]=s[i-1]+1;
            else
                s[i]=s[i-1];
        }

        for(i=1;i+k-1<=n;i++)
        {
            if(maxi<s[i+k-2]-s[i])
            {
                maxi=s[i+k-2]-s[i];
                imaxi=i;
            }
        }
        cout<<maxi+1<<' '<<imaxi<<'\n';
    }
    return 0;
}
