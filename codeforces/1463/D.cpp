#include <bits/stdc++.h>

using namespace std;

int pMax(vector<int> &a, vector<int> &b)
{
    int p=0;

    for(int i=0;i<a.size();i++)
    {
        while(p<b.size() && b[p]<a[i])
            p++;

        if(p>=b.size())
            return i;
        p++;
    }

    return a.size();
}

int t,n,x;
vector<int> b,nb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;

        b.clear();
        nb.clear();

        for(int i=1;i<=n;i++)
        {
            cin>>x;
            b.push_back(x);
        }

        for(int i=1;i<=2*n;i++)
        {
            if(!binary_search(b.begin(), b.end(), i))
                nb.push_back(i);
        }

        int r=pMax(b, nb);
        int l=n-pMax(nb, b);

        cout<<r-l+1<<'\n';
    }
    return 0;
}
