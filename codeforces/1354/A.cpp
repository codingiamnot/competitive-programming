#include <iostream>

using namespace std;
long long a,b,c,d,nr,t;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b>>c>>d;
        if(a<=b)
        {
            cout<<b<<'\n';
            continue;
        }

        a-=b;

        if(d>=c)
        {
            cout<<-1<<'\n';
            continue;
        }

        nr=(a+c-d-1)/(c-d);
        cout<<b+nr*c<<'\n';
    }
    return 0;
}
