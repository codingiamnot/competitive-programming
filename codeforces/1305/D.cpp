#include <bits/stdc++.h>

using namespace std;
int n,i,x,y;
int p1, p2, ans;
struct nodS
{
    vector <int> vecini;
    int leg=0;
} nod[1005];
queue <int> q;
int main()
{
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back(y);
        nod[x].leg++;
        nod[y].vecini.push_back(x);
        nod[y].leg++;
    }

    for(i=1;i<=n;i++)
    {
        if(nod[i].leg==1)
            q.push(i);
    }
    while(!q.empty())
    {
        if(q.size()==1)
        {
            cout<<"! "<<q.front();
            return 0;
        }
        p1 = q.front();
        q.pop();
        p2 = q.front();
        q.pop();

        cout<<"? "<<p1<<' '<<p2<<endl;
        cin>>ans;

        if(ans==p1)
        {
            cout<<"! "<<p1;
            return 0;
        }

        if(ans==p2)
        {
            cout<<"! "<<p2;
            return 0;
        }

        for(auto it : nod[p1].vecini)
        {
            nod[it].leg--;
            if(nod[it].leg==1)
                q.push(it);
        }

        for(auto it : nod[p2].vecini)
        {
            nod[it].leg--;
            if(nod[it].leg==1)
                q.push(it);
        }
    }
    return 0;
}
