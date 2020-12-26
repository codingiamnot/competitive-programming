#include <bits/stdc++.h>

using namespace std;

int t,n,m;

struct pos
{
    int x, y, z;

    pos(){}
    pos(int x, int y, int z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }

    bool operator==(pos b)
    {
        return (x==b.x && y==b.y && z==b.z);
    }
    pos operator+(pos b)
    {
        pos ans;

        ans.x=x+b.x;
        ans.y=y+b.y;
        ans.z=z+b.z;

        ans.calc();

        return ans;
    }

    pos operator*(int k)
    {
        pos ans;

        ans.x=x*k;
        ans.y=y*k;
        ans.z=z*k;

        ans.calc();

        return ans;
    }

    void calc()
    {
        x%=n;
        y%=n;
        z%=n;
    }
};

int i,j;
char ch;
int a[1005][1005];
int b[1005][1005];
pos v0,vx,vy,vz,nv;

int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
                a[i][j]--;
            }

        v0=pos(0, 0, 0);
        vx=pos(1, 0, 0);
        vy=pos(0, 1, 0);
        vz=pos(0, 0, 1);

        for(i=1;i<=m;i++)
        {
            cin>>ch;

            if(ch=='D')
                v0.x++;
            if(ch=='U')
                v0.x+=n-1;

            if(ch=='R')
                v0.y++;
            if(ch=='L')
                v0.y+=n-1;

            if(ch=='I')
            {
                swap(v0.y, v0.z);

                if(vx==pos(0, 1, 0))
                {
                    if(vy==pos(0, 0, 1))
                        swap(vx, vy);
                    else
                        swap(vx, vz);
                }
                else if(vy==pos(0, 1, 0))
                {
                    if(vx==pos(0, 0, 1))
                        swap(vx, vy);
                    else
                        swap(vz, vy);
                }
                else if(vz==pos(0, 1, 0))
                {
                    if(vx==pos(0, 0, 1))
                        swap(vx, vz);
                    else
                        swap(vy, vz);
                }
            }
            if(ch=='C')
            {
                swap(v0.x, v0.z);

                if(vx==pos(1, 0, 0))
                {
                    if(vy==pos(0, 0, 1))
                        swap(vx, vy);
                    else
                        swap(vx, vz);
                }
                else if(vy==pos(1, 0, 0))
                {
                    if(vx==pos(0, 0, 1))
                        swap(vx, vy);
                    else
                        swap(vz, vy);
                }
                else if(vz==pos(1, 0, 0))
                {
                    if(vx==pos(0, 0, 1))
                        swap(vx, vz);
                    else
                        swap(vy, vz);
                }
            }

            v0.calc();
        }

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                nv=v0+vx*i+vy*j+vz*a[i][j];
                nv.calc();

                b[nv.x][nv.y]=nv.z;
            }

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                cout<<b[i][j]+1<<' ';
            cout<<'\n';
        }
    }
}
