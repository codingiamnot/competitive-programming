#include <bits/stdc++.h>

using namespace std;

long long n,x,i;
char ch;
long long a[100005];
int main()
{
    cin>>n>>x;

    for(i=1;i<=n;i++)
    {
        cin>>ch;
        a[i]=ch-'a';
    }

    x-=(long long)1<<a[n];
    x+=(long long)1<<a[n-1];

    n-=2;
    sort(a+1, a+n+1);

    for(i=n;i>=1;i--)
    {
        if(x>0)
            x-=(long long)1<<a[i];
        else
            x+=(long long)1<<a[i];
    }

    if(x)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}
