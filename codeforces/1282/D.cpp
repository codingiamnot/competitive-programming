#include <bits/stdc++.h>

using namespace std;
int query(string &a)
{
    int ans;
    cout<<a<<'\n';
    cin>>ans;
    if(!ans)
        exit(0);
    return ans;
}
int n,i,val1,val2,nr;
string s;
int main()
{
    s.push_back('a');
    val1=query(s);

    n=val1+1;
    if(n>300)
    {
        n--;
        s.clear();
        for(i=1;i<=n;i++)
            s.push_back('b');
        query(s);
        return 0;
    }

    s.clear();
    for(i=1;i<=n;i++)
        s.push_back('a');

    val2=query(s);
    if(val2==val1+1)
    {
        n--;
        s.clear();
        for(i=1;i<=n;i++)
            s.push_back('b');
        query(s);
        return 0;
    }

    nr=val2;

    for(i=0;i<n-1;i++)
    {
        s[i]='b';

        if(query(s)<nr)
            nr--;
        else
            s[i]='a';
    }

    if(nr)
        s[n-1]='b';

    query(s);
    return 0;
}
