#include <iostream>

using namespace std;
int n, t;
double p,ans;
double pb[2005][2005];
int main()
{
    cin>>n>>p>>t;
    pb[0][0]=1;
    for(int timp=1; timp<=t; timp++)
    {
        for(int pers=0; pers<=n; pers++)
        {
            if(pers==n)
                pb[timp][pers]=pb[timp-1][pers];
            else
                pb[timp][pers]=pb[timp-1][pers]*(1-p);

            if(pers>0)
                pb[timp][pers]+=pb[timp-1][pers-1]*p;
        }
    }

    for(int pers=1; pers<=n; pers++)
        ans += pb[t][pers]*pers;

    cout.precision(12);
    cout<<ans;
    return 0;
}
