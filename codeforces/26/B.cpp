#include <iostream>

using namespace std;
string s;
int sum, nr;
int main()
{
    cin>>s;
    for(char it : s)
    {
        if(it=='(')
            sum++;
        else
            sum--;

        if(sum==-1)
        {
            nr++;
            sum++;
        }
    }
    nr+=sum;
    cout<<s.size()-nr;
    return 0;
}
