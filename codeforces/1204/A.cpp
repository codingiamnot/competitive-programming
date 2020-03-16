#include <iostream>

using namespace std;
string s;
int n,i;
bool ok;
int main()
{
    cin>>s;
    n=s.size();
    for(i=1;i<n;i++)
    {
        if(s[i]=='1')
        {
            ok=true;
            break;
        }
    }
    if(ok)
        cout<<(n+1)/2;
    else
        cout<<n/2;
    return 0;
}
