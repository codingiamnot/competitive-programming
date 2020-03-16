#include <iostream>

using namespace std;
string s1,s2,ans;
int main()
{
    cin>>s1>>s2;
    ans.push_back(s1.front());
    s1.erase(s1.begin());

    while(!s1.empty() && s1.front()<s2.front())
    {
        ans.push_back(s1.front());
        s1.erase(s1.begin());
    }
    ans.push_back(s2.front());
    cout<<ans;
    return 0;
}
