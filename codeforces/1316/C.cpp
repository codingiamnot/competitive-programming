#include <bits/stdc++.h>

using namespace std;
int n,m,p,i,x,ans1,ans2;
bool ok1,ok2;
int main()
{
    cin>>n>>m>>p;
    ok1=false;
    ok2=false;
    for(i=1;i<=n;i++)
    {
        scanf("%d", &x);
        if(x%p && !ok1)
        {
            ans1=i;
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d", &x);
        if(x%p && !ok2)
        {
            ans2=i;
        }
    }

    cout<<ans1+ans2-2;
    return 0;
}
