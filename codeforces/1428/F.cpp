#include <iostream>

using namespace std;
int n,i,p,l,r,x;
long long ans,cur,dif;
char ch;
int v[500005];
int h[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ch;
        v[i]=ch-'0';
    }

    for(i=1;i<=n;i++)
    {
        if(!v[i])
            ans+=cur;
        else
        {
            l=i;
            r=i;
            while(r<n && v[r+1])
                r++;

            for(x=1;x<=r-l+1;x++)
            {
                cur+=(l+x-1) - h[x];
                ans+=cur;
                h[x]=r-x+1;
            }

            i=r;
        }
    }

    cout<<ans;
    return 0;
}
