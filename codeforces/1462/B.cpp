#include <iostream>

using namespace std;

int t,a,b,n,i;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tar="2020";

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        cin>>s;

        if(n<4)
        {
            cout<<"NO\n";
            continue;
        }

        a=0;
        b=0;

        for(i=0;i<4;i++)
        {
            if(s[i]==tar[i])
                a++;
            else
                break;
        }

        for(i=0;i<4;i++)
        {
            if(s[n-i-1]==tar[4-i-1])
                b++;
            else
                break;
        }

        if(a+b>=4)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
