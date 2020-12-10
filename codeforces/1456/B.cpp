#include <iostream>

using namespace std;

int n,i,j,k,ans,a,b;
int v[100005];
int main()
{
    cin>>n;
    if(n>60)
    {
        cout<<1;
        return 0;
    }

    for(i=1;i<=n;i++)
        cin>>v[i];

    ans=n+1;

    for(i=1;i<=n;i++)
    {
        a=0;
        for(j=i;j<=n;j++)
        {
            a^=v[j];
            b=0;

            for(k=j+1;k<=n;k++)
            {
                b^=v[k];

                if(a>b)
                    ans=min(ans, j-i+k-j-1);
            }
        }
    }

    if(ans==n+1)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
