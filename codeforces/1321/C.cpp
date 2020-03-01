#include <iostream>

using namespace std;
int nr,n,i,j,ok[105];
char s[105];
char ch;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>s[i];
    for(ch='z';ch>='b';ch--)
    {
        for(i=1;i<=n;i++)
        {
            if(s[i]!=ch)
                continue;

            for(j=i-1;j>=1;j--)
            {
                if(s[j]+1==s[i])
                {
                    ok[i]=true;
                    break;
                }
                if(s[j]==ch)
                    continue;

                if(!ok[j])
                    break;
            }

            for(j=i+1;j<=n;j++)
            {
                if(s[j]+1==s[i])
                {
                    ok[i]=true;
                    break;
                }
                if(s[j]==ch)
                    continue;

                if(!ok[j])
                    break;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(ok[i])
            nr++;
    }
    cout<<nr;
    return 0;
}
