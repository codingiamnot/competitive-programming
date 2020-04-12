#include <bits/stdc++.h>

using namespace std;
int t,n,i,mij;
int a[100005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];

        sort(a+1, a+n+1);

        if(n%2==0)
        {
            mij=n/2;
            cout<<a[mij]<<' '<<a[mij+1]<<' ';
            for(i=1;i<2*mij-1;i++)
            {
                if(i%2==1)
                {
                    cout<<a[mij-i/2-1]<<' ';
                }
                else
                {
                    cout<<a[mij+1+i/2]<<' ';
                }
            }
        }
        else
        {
            mij=n/2+1;
            cout<<a[mij]<<' ';
            for(i=1;i<2*mij-1;i++)
            {
                if(i%2==1)
                    cout<<a[mij-i/2-1]<<' ';
                else
                    cout<<a[mij+i/2]<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}
