#include <bits/stdc++.h>

using namespace std;
struct pos
{
	char t;
    int x, y;
    pos(int x, int y)
    {
        this->x=x;
        this->y=y;
        t='B';
    }
};
struct stack_dsu
{
	vector<int> par, sz;
	vector<pair<int, int>> act;

	void init(int n)
	{
		par.resize(n+1);
		sz.resize(n+1);

		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
	}
	int fpar(int x)
	{
		if(par[x]==x)
			return x;
		return fpar(par[x]);
	}
	void fmerge(int x, int y)
	{
		x=fpar(x);
		y=fpar(y);

		if(x!=y)
		{
			if(sz[x]>sz[y])
				swap(x, y);

			par[x]=y;
			sz[y]+=sz[x];
		}

		act.push_back({x, y});
	}
	void pop()
	{
		if(act.empty())
			return;

		int x=act.back().first;
		int y=act.back().second;
		act.pop_back();

		if(x==y)
			return;

		par[x]=x;
		sz[y]-=sz[x];
	}
};
struct queue_dsu
{
	int bottom;
	vector<pos> act;
	stack_dsu s;

	void init(int n)
	{
		s.init(n);
	}
	void fmerge(int x, int y)
	{
		act.push_back(pos(x, y));
		s.fmerge(x, y);
	}

	void move_bottom()
	{
		while(bottom<act.size() && act[bottom].t=='B')
			bottom++;
	}
	void reverse_upd()
	{
		for(int i=0;i<act.size();i++)
		{
			s.pop();
			act[i].t='A';
		}

		reverse(act.begin(), act.end());

		for(int i=0;i<act.size();i++)
            s.fmerge(act[i].x, act[i].y);

        bottom=0;
    }
    void fix()
    {
        if(act.empty() || act.back().t=='A')
            return;

        move_bottom();
        vector<pos> va, vb;
        vb.push_back(act.back());
        act.pop_back();
        s.pop();

        while(va.size()!=vb.size() && act.size()>bottom)
        {
            if(act.back().t=='A')
                va.push_back(act.back());
            else
                vb.push_back(act.back());

            act.pop_back();
            s.pop();
        }

        reverse(va.begin(), va.end());
        reverse(vb.begin(), vb.end());

        for(auto it : vb)
        {
            act.push_back(it);
            s.fmerge(it.x, it.y);
        }
        for(auto it : va)
        {
            act.push_back(it);
            s.fmerge(it.x, it.y);
        }
        move_bottom();
    }
    void pop()
    {
        move_bottom();
        if(bottom==act.size())
            reverse_upd();

        fix();
        act.pop_back();
        s.pop();
    }
};
int n,k,q,day,t,x,y;
int nr[600005];
queue_dsu dsu;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>q>>k;
	dsu.init(n);
	day=1;
	while(q)
	{
		q--;
		cin>>t;
		if(t==1)
		{
			cin>>x>>y;
			dsu.fmerge(x, y);
			nr[day+k]++;
		}
		if(t==2)
		{
			cin>>x;
			cout<<dsu.s.sz[dsu.s.fpar(x)]<<'\n';
		}
		if(t==3)
		{
			day++;
			while(nr[day])
			{
				nr[day]--;
				dsu.pop();
			}
		}
	}
    return 0;
}
