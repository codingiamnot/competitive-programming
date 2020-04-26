#include <iostream>

using namespace std;
string s;
int t,i,nr;
bool ok0,ok1;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        ok0=false;
        ok1=false;
        cin>>s;
        nr=s.size();

        for(i=0;i<nr;i++)
        {
            if(s[i]=='0')
                ok0=true;
            else
                ok1=true;
        }

        if(ok0 && ok1)
        {
            cout<<s[0];
            for(i=1;i<nr;i++)
            {
                if(s[i]==s[i-1])
                {
                    if(s[i]=='1')
                        cout<<'0';
                    else
                        cout<<'1';
                }
                cout<<s[i];
            }
            cout<<'\n';
        }
        else
        {
            cout<<s<<'\n';
        }
    }
    return 0;
}
