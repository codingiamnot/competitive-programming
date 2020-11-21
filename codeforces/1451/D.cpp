#include <bits/stdc++.h>

using namespace std;

long long t,d,k;
bool bad(long long a, long long b)
{
    return a*a+b*b>d*d;
}
bool solve(long long a, long long b)
{
    if(bad(a, b))
        return true;

    if(!bad(a+k, b+k))
        return solve(a+k, b+k);

    if(!solve(a+k, b))
        return true;

    if(!solve(a, b+k))
        return true;

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>d>>k;

        if(solve(0, 0))
            cout<<"Ashish\n";
        else
            cout<<"Utkarsh\n";
    }
    return 0;
}
