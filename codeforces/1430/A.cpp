#include <bits/stdc++.h>

using namespace std;
int t,n,nr3,nr5,nr7;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;

        nr3=n/3;
        nr5=0;
        nr7=0;

        if(n%3==1)
        {
            nr3-=2;
            nr7++;
        }
        if(n%3==2)
        {
            nr3--;
            nr5++;
        }

        if(nr3<0)
            cout<<"-1\n";
        else
            cout<<nr3<<' '<<nr5<<' '<<nr7<<'\n';
    }
    return 0;
}
