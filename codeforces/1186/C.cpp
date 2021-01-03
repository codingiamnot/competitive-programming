#include <iostream>

using namespace std;

string s,t;
int n,k,i,nr,cnt;
int main()
{
    cin>>s;
    cin>>t;

    int k=t.size();
    int n=s.size();

    for(i=0;i<k;i++)
        if(t[i]=='1')
            nr++;

    for(i=0;i<k;i++)
        if(s[i]=='1')
            nr++;

    if(nr%2==0)
        cnt++;

    for(i=k;i<n;i++)
    {
        if(s[i]=='1')
            nr++;
        if(s[i-k]=='1')
            nr--;

        if(nr%2==0)
            cnt++;
    }

    cout<<cnt;
    return 0;
}
