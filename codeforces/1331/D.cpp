#include <iostream>

using namespace std;
int i;
char ch;
int main()
{
    for(i=1;i<=7;i++)
        cin>>ch;

    cout<<(ch-'0')%2;
    return 0;
}
