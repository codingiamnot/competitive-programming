#include <bits/stdc++.h>

using namespace std;
long long t,x,nr,cif;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>x;
        cif=x%10;
        nr=0;
        while(x)
        {
            x/=10;
            nr++;
        }

        cout<<10*(cif-1)+nr*(nr+1)/2<<'\n';
    }
    return 0;
}
