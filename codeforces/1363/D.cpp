#include <bits/stdc++.h>

using namespace std;
int t,n,k,i,nr,x,maxi,st,dr,mij,ansl,maxis;
int fr[1005];
int ans[1005];
vector <int> v[1005];
string response;
int q(vector<int> &v)
{
    int ans;
    cout<<"? ";
    cout<<v.size()<<' ';
    for(int it : v)
        cout<<it<<' ';
    cout<<endl;
    cin>>ans;
    return ans;
}
int qsecv(int l, int r)
{
    vector <int> qv;
    for(int i=l;i<=r;i++)
    {
        for(int it : v[i])
            qv.push_back(it);
    }
    return q(qv);
}
int qmaxi()
{
    int ans;
    cout<<"? ";
    cout<<n<<' ';
    for(i=1;i<=n;i++)
        cout<<i<<' ';
    cout<<endl;
    cin>>ans;
    return ans;
}
void setans(int l, int r)
{
    for(int i=l;i<=r;i++)
        ans[i]=maxi;
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        for(i=1;i<=k;i++)
            v[i].clear();

        for(i=1;i<=k;i++)
        {
            cin>>nr;
            while(nr)
            {
                nr--;
                cin>>x;
                v[i].push_back(x);
            }
        }
        maxi=qmaxi();
        st=1;
        dr=k;
        while(st<=dr)
        {
            if(st==dr)
            {
                vector <int> qv;
                memset(fr, 0, sizeof fr);
                for(int it : v[st])
                    fr[it]=1;
                for(i=1;i<=n;i++)
                    if(!fr[i])
                        qv.push_back(i);
                ans[st]=q(qv);
                break;
            }
            mij=(st+dr)/2;
            ansl=qsecv(st, mij);
            if(ansl==maxi)
            {
                setans(mij+1, dr);
                dr=mij;
            }
            else
            {
                setans(st, mij);
                st=mij+1;
            }
        }

        cout<<"! ";
        for(i=1;i<=k;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
        cin>>response;
        if(response=="Incorrect")
            return 0;
    }
    return 0;
}
