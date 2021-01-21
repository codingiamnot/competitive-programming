#include <iostream>

using namespace std;

char ch;
int t,n,i,last;
int a[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;

        for(i=1;i<=n;i++)
        {
            cin>>ch;
            a[i]=ch-'0';
        }

        last=-1;
        for(i=1;i<=n;i++)
        {
            if(1+a[i]!=last)
            {
                last=1+a[i];
                cout<<1;
            }
            else
            {
                last=a[i];
                cout<<0;
            }
        }

        cout<<'\n';
    }
    return 0;
}
