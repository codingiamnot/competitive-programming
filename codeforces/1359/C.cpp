#include <iostream>

using namespace std;
int q;
long long h,c,t,st,dr,last,mij;
long long f(long long x)
{
    return x*(h+c-2*t)-t+h;
}
bool comp(long long x)
{
    long double a=(double)f(x)/(2*x+1);
    long double b=(double)f(x+1)/(2*x+3);
    b=-b;

    return a<=b;
}
int main()
{
    cin>>q;
    while(q)
    {
        q--;
        cin>>h>>c>>t;
        if(t>=h)
        {
            cout<<"1\n";
            continue;
        }
        if(2*t<=h+c)
        {
            cout<<"2\n";
            continue;
        }

        st=0;
        dr=1e9;
        last=0;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            if(f(mij)>=0)
            {
                last=mij;
                st=mij+1;
            }
            else
                dr=mij-1;
        }
        if(comp(last))
            cout<<2*last+1<<'\n';
        else
            cout<<2*last+3<<'\n';
    }
    return 0;
}
