#include <iostream>

using namespace std;
int n,i,j,x,maxi;
int st,dr,mij,last;
int nval,ans,ansl,ansr;
int fr[200005];
int s[200005];
int s2[200005];
int ok(int l, int r)
{
    if(!fr[r+1])
        return false;

    if(l>r)
        return true;

    return s2[r]-s2[l-1]>=r-l+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        maxi=max(maxi, x);
        fr[x]++;
    }
    for(i=1;i<=maxi;i++)
        s[i]=s[i-1]+fr[i];
    for(i=1;i<=maxi;i++)
    {
        s2[i]=s2[i-1];
        if(fr[i]>=2)
            s2[i]++;
    }

    for(i=1;i<=maxi;i++)
    {
        if(!fr[i])
            continue;

        st=i+1;
        dr=maxi;
        last=i;

        while(st<=dr)
        {
            mij=(st+dr)/2;

            if(ok(i+1, mij-1))
            {
                last=mij;
                st=mij+1;
            }
            else
                dr=mij-1;
        }

        nval=s[last]-s[i-1];
        if(nval>ans)
        {
            ans=nval;
            ansl=i;
            ansr=last;
        }
    }

    if(ansl==ansr)
    {
        cout<<ans<<'\n';
        for(i=1;i<=fr[ansl];i++)
            cout<<ansl<<' ';
        return 0;
    }

    cout<<ans<<'\n';
    for(i=1;i<=fr[ansl];i++)
        cout<<ansl<<' ';
    for(i=ansl+1;i<ansr;i++)
        for(j=1;j<fr[i];j++)
            cout<<i<<' ';
    for(i=1;i<=fr[ansr];i++)
        cout<<ansr<<' ';
    for(i=ansr-1;i>ansl;i--)
        cout<<i<<' ';
    return 0;
}
