#include <iostream>

using namespace std;
long long t,a,b,c,d,k;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b>>c>>d;
        if(a>b*c)
        {
            cout<<"-1\n";
            continue;
        }

        k=a/(b*d);

        cout<<a*(k+1)-k*(k+1)*b*d/2<<'\n';
    }
    return 0;
}
