#include <iostream>

using namespace std;
int n,i,j,ans;
int s[1000005];
char ch;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ch;
        if(ch=='(')
            s[i]=s[i-1]+1;
        else
            s[i]=s[i-1]-1;
    }
    if(s[n])
    {
        cout<<-1;
        return 0;
    }

    for(i=1;i<=n;i++)
    {
        if(s[i]!=-1)
            continue;

        for(j=i+1;j<=n;j++)
            if(!s[j])
        {
            break;
        }

        ans+=j-i+1;
        i=j;
    }

    cout<<ans;
    return 0;
}
