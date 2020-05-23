#include <bits/stdc++.h>

using namespace std;
int n,x,i,nr;
vector <int> ans;
int main()
{
    cin>>n>>x;
    if(x>(1<<n)-1)
    {
        for(i=1;i<(1<<n);i++)
        {
            ans.push_back(i);
        }
    }
    else
    {
        for(i=1;i<(1<<n);i++)
        {
            if(i<(x^i))
                ans.push_back(i);
        }
    }

    nr=ans.size();
    cout<<nr<<'\n';
    for(i=0;i<nr;i++)
    {
        if(!i)
            cout<<ans[i]<<' ';
        else
            cout<<(ans[i]^ans[i-1])<<' ';
    }
    return 0;
}
