#include <bits/stdc++.h>
#define PI 3.14159265359

using namespace std;
double n,angle,r;
int t;
int main()
{
    cin>>t;
    cout.precision(12);
    while(t)
    {
        t--;
        cin>>n;
        if(n==2)
        {
            cout<<"1\n";
            continue;
        }
        angle=tan(PI/(2*n));
        r=1/(2*angle);
        cout<<2*r<<'\n';
    }
    return 0;
}
