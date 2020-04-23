#include <iostream>

using namespace std;
int t,n,i,maxi,mini;
int a[100005];
bool ok;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ok=true;
        maxi=0;
        mini=0;

        for(i=1;i<=n;i++)
            cin>>a[i];
        a[n+1]=0;
        for(i=n;i>=1;i--)
        {
            if(a[i]==a[i+1]-1)
                continue;

            if(a[i+1]==mini)
            {
                mini=maxi+1;
                maxi=a[i];
            }
            else
            {
                ok=false;
            }
        }

        if(ok)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
