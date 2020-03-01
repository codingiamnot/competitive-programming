#include <iostream>

using namespace std;
int a[105],b[105],nrb,nrg,i,n;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>b[i];

    for(i=1;i<=n;i++)
    {
        if(a[i] && !b[i])
            nrg++;

        if(!a[i] && b[i])
            nrb++;
    }

    if(!nrg)
    {
        cout<<-1;
        return 0;
    }
    cout<<nrb/nrg+1;
    return 0;
}
