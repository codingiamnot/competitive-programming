#include <bits/stdc++.h>

using namespace std;
int l,r;
char mij;
string s,ans;
string rez(int l, int r)
{
    if(l>r)
        return "";
    if(r-l+1<=3)
    {
        mij=s[0];
        return "";
    }

    if(s[l]==s[r] || s[l]==s[r-1])
        return s[l]+rez(l+2, r-2);
    return s[l+1]+rez(l+2, r-2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    l=0;
    r=s.size()-1;
    while(true)
    {
        if(l>r)
            break;
        if(r-l+1<=3)
        {
            mij=s[l];
            break;
        }

        if(s[l]==s[r] || s[l]==s[r-1])
            ans.push_back(s[l]);
        else
            ans.push_back(s[l+1]);

        l+=2;
        r-=2;
    }

    cout<<ans;
    if(mij)
        cout<<mij;
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    return 0;
}
