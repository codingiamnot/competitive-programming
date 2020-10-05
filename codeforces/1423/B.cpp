#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

int N, viz[21000],L[20100], R[20100];
vector <int> hey;
vector <pii> l[20100];
inline void scan() {
    int u,v,E,cost;
    cin>>N>>E;
    for(int i=1; i<=E; ++i)
    {
        cin>>u>>v>>cost;
        hey.push_back(cost);
        l[u].push_back({v,cost});
    }
}

inline bool cup(int x, int valmax)
{
    viz[x]=1;

    for(auto it:l[x])
        if(!R[it.first] && it.second<=valmax)
            {
            L[x]=it.first;
            R[it.first]=x;
            return 1;
            }

    for(auto it:l[x])
        if(!viz[R[it.first]] && it.second<=valmax && cup(R[it.first],valmax))
        {
            L[x]=it.first;
            R[it.first]=x;
            return 1;
        }

    return 0;
}

bool ok;
bool verif(int valmax)
{
    do{
        ok=0;
        for(int i=1; i<=N; ++i)
            if(!viz[i] && !L[i])
                ok=max(ok,cup(i,valmax));
        for(int i=1; i<=N; viz[i++]=0);

    }while(ok);

    int lg=0;
    for(int i=1; i<=N; lg+=(L[i]!=0),L[i]=0, R[i]=0,++i);

    return (lg==N);
}
int main()
{
    scan();

    sort(hey.begin(),hey.end());
    int st,dr,mij,ans;
    st=0; dr=hey.size()-1;
    ans=-1;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(verif(hey[mij]))
        {
            ans=hey[mij];
            dr=mij-1;
        }
        else st=mij+1;
    }
    cout<<ans<<'\n';
    return 0;
}
