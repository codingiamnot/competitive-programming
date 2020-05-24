#include <iostream>

using namespace std;
long long a,b,n,l,m,t,mij,st,dr,last,maxi,sum;
int main()
{
    cin>>a>>b>>n;
    while(n)
    {
        n--;
        cin>>l>>t>>m;
        if(a+b*(l-1)>t)
        {
            cout<<"-1\n";
            continue;
        }

        st=l;
        dr=1e12;
        last=-1;

        while(st<=dr)
        {
            mij=(st+dr)/2;

            maxi=a+b*(mij-1);
            sum=a*(mij-l+1);
            sum+=b*(mij*(mij-1)/2 - (l-1)*(l-2)/2);

            if(maxi<=t && sum<=m*t)
            {
                st=mij+1;
                last=mij;
            }
            else
                dr=mij-1;
        }

        cout<<last<<'\n';
    }
    return 0;
}
