#include <iostream>

using namespace std;
int i,j,t,n,k,nr;
int gr[200005];
int fr[200005][30];
int s,maxi,ans;
char ch;
void dfs(int poz)
{
    gr[poz]=nr;

    int i=1;

    if(!gr[(n-poz+1)%k])
        dfs((n-poz+1)%k);

}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        ans=0;
        nr=0;
        for(i=1; i<=n; i++)
            gr[i]=0;

        for(i=1; i<=k; i++)
        {
            if(!gr[i])
            {
                nr++;
                dfs(i);
            }
        }

        for(i=1; i<=n; i++)
        {
            cin>>ch;
            fr[gr[i%k]][ch-'a']++;
        }

        for(i=1; i<=nr; i++)
        {
            s=0;
            maxi=0;

            for(j=0; j<26; j++)
            {
                s+=fr[i][j];
                maxi=max(maxi, fr[i][j]);
            }

            ans+=s-maxi;
        }

        cout<<ans<<'\n';

        for(i=1; i<=nr; i++)
            for(j=0; j<26; j++)
                fr[i][j]=0;
    }
    return 0;
}
