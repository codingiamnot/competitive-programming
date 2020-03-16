#include <bits/stdc++.h>

using namespace std;
int n,i;
int ans[100005];
stack <int> st;
string s;
int main()
{
    cin>>s;
    st.push(0);
    n=s.size();
    for(i=1;i<n;i++)
    {
        if(st.empty())
        {
            st.push(i);
            continue;
        }
        if(s[i]=='0' && s[st.top()]=='1')
        {
            ans[i]=1;
            ans[st.top()]=1;
            st.pop();
        }
        else
        {
            st.push(i);
        }
    }
    for(i=0;i<n;i++)
    {
        if(ans[i]==1)
            cout<<s[i];
        else
            cout<<0;
    }
    return 0;
}
