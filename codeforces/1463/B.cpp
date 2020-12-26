#include <bits/stdc++.h>

using namespace std;

int t,n,i;
int a[55];
long long s[4];

int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        s[0]=s[1]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            s[i%2]+=a[i];
        }
        
        if(s[0]==s[1])
            s[0]++;
        
        for(i=1;i<=n;i++)
        {
            if(s[i%2]>=s[(i+1)%2])
                cout<<a[i]<<' ';
            else
                cout<<"1 ";
        }
        cout<<'\n';
    }
    return 0;
}
