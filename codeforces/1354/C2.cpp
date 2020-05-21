#include <bits/stdc++.h>
#define PI 3.14159265359

using namespace std;
double n;
int t;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        cout.precision(12);
        cout<<cos(PI/(4*n))/sin(PI/(2*n))<<'\n';
    }
    return 0;
}
