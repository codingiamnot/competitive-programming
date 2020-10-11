#include <bits/stdc++.h>

using namespace std;
struct pos
{
    int st, dr;
    pos(int st, int dr)
    {
        this->st=st;
        this->dr=dr;
    }
};
struct ansS
{
    int a, b, c, d;
    ansS(int a, int b, int c, int d)
    {
        this->a=a;
        this->b=b;
        this->c=c;
        this->d=d;
    }
};
int n,i,j,k,nr;
int ans1, ans2, ans3, ans4;
bool ok;
int a[105], a2[105];
bool comp(int i, int j)
{
    return a[i]<a[j];
}
vector<pos> v, nv;
vector<ansS> ans;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        a2[i]=i;
    }
    sort(a2+1, a2+n+1, comp);
    for(i=1;i<=n;i++)
        a[a2[i]]=i;
    for(i=1;i<=n;i++)
        v.push_back(pos(a[i], a[i]));

    ok=true;
    while(ok)
    {
        /*
        for(auto it : v)
        {
            cout<<it.st<<' '<<it.dr<<'\n';
        }
        cout<<'\n';
        */

        ok=false;
        for(i=0;i<v.size();i++)
        {
            for(j=i+1;j<v.size();j++)
            {
                if(v[i].st==v[j].dr+1)
                {
                    ok=true;
                    break;
                }
            }
            if(ok)
                break;
        }


        if(!ok)
            break;

        ans1=0;
        for(k=0;k<i;k++)
            ans1+=v[k].dr-v[k].st+1;

        ans2=0;
        for(k=i;k<j;k++)
            ans2+=v[k].dr-v[k].st+1;

        ans3=v[j].dr-v[j].st+1;

        ans4=0;
        for(k=j+1;k<v.size();k++)
            ans4+=v[k].dr-v[k].st+1;

        ans.push_back(ansS(ans1, ans2, ans3, ans4));


        nv.clear();
        for(k=j+1;k<v.size();k++)
            nv.push_back(v[k]);

        nv.push_back(pos(v[j].st, v[i].dr));

        for(k=i+1;k<j;k++)
            nv.push_back(v[k]);

        for(k=0;k<i;k++)
            nv.push_back(v[k]);

        v=nv;
    }

    cout<<ans.size()<<'\n';
    for(auto it : ans)
    {
        nr=(it.a>0)+(it.b>0)+(it.c>0)+(it.d>0);
        cout<<nr<<' ';

        if(it.a)
            cout<<it.a<<' ';
        if(it.b)
            cout<<it.b<<' ';
        if(it.c)
            cout<<it.c<<' ';
        if(it.d)
            cout<<it.d<<' ';
        cout<<'\n';
    }
    return 0;
}
