#include <bits/stdc++.h>

using namespace std;
int t,i,nr;
long long n,sum;
vector <long long> v;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        if(n==2)
        {
            cout<<"1\n";
            cout<<"0\n";
            continue;
        }
        v.clear();
        sum=0;
        for(i=0;i<=64;i++)
        {
            sum+=(1<<i);
            v.push_back(1<<i);
            if(n==sum)
                break;
            if(sum+(1<<(i+1))>n)
            {
                v.push_back(n-sum);
                break;
            }
        }
        sort(v.begin(), v.end());
        nr=v.size();
        cout<<nr-1<<'\n';
        for(i=1;i<nr;i++)
            cout<<v[i]-v[i-1]<<' ';
        cout<<'\n';
    }
    return 0;
}
