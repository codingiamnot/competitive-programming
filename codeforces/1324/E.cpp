#include <bits/stdc++.h>

using namespace std;
int i,n,j,l,r,h,somn,ans;
int a[2005];
map <int, int> m,mv;
inline bool apar(int nr)
{
    nr%=h;
    return (nr>=l && nr<=r);
}
int main()
{
    cin>>n>>h>>l>>r;

    for(i=1;i<=n;i++)
        cin>>a[i];

    m[a[1]]=0;
    m[a[1]-1]=0;
    if(apar(a[1]))
        m[a[1]]++;
    if(apar(a[1]-1))
        m[a[1]-1]++;

    for(i=2;i<=n;i++)
    {
        mv=m;
        m.clear();

        for(auto it : mv)
        {
            somn=it.first+h+a[i];
            if(apar(somn))
                m[somn]=max(m[somn], it.second+1);
            else
                m[somn]=max(m[somn], it.second);

            somn--;
            if(apar(somn))
                m[somn]=max(m[somn], it.second+1);
            else
                m[somn]=max(m[somn], it.second);
        }
    }

    for(auto it : m)
        ans=max(ans, it.second);

    cout<<ans;
    return 0;
}
