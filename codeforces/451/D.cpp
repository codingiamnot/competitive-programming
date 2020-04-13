#include <iostream>

using namespace std;
string s;
long long n,i,ap,ai,bp,bi,ansp,ansi;
int main()
{
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(s[i]=='a')
        {
            if(i%2==1)
            {
                ansp+=ap;
                ansi+=ai;
                ai++;
            }
            else
            {
                ansp+=ai;
                ansi+=ap;
                ap++;
            }
        }

        else
        {
            if(i%2==1)
            {
                ansp+=bp;
                ansi+=bi;
                bi++;
            }
            else
            {
                ansp+=bi;
                ansi+=bp;
                bp++;
            }
        }
    }

    cout<<ansp<<' '<<ansi+n;
    return 0;
}
