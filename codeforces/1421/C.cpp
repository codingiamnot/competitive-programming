#include <iostream>

using namespace std;
string s;
int n;
int main()
{
    cin>>s;
    n=s.size();

    cout<<"3\n";
    cout<<"R "<<2<<'\n';
    cout<<"L "<<n<<'\n';
    cout<<"L "<<n-1<<'\n';
    return 0;
}
