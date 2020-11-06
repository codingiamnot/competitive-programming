#include <bits/stdc++.h>

using namespace std;

struct pos
{
	long long x, y, t;
	pos(long long x, long long y, long long t)
	{
		this->x=x;
		this->y=y;
		this->t=t;
	}
};
long long x, y, b;
vector<pos> ans;
void mul(long long baza, long long nr)
{
	if(nr==1)
		return;
		
	mul(baza, nr/2);
	ans.push_back(pos(baza*(nr/2), baza*(nr/2), 2)); 
	
	if(nr%2)
		ans.push_back(pos(baza*(nr/2)*2, baza, 2));
}
pair<long long, long long> euclidExtins(long long a, long long b)
{
	pair<long long, long long> pa, pb;
	long long nr;
	pa={1, 0};
	pb={0, 1};
	
	if(a<b)
	{
		swap(a, b);
		swap(pa, pb);
	}
	
	while(b>1)
	{
		nr=a/b;
		
		a-=nr*b;
		pa.first-=nr*pb.first;
		pa.second-=nr*pb.second;
		
		swap(a, b);
		swap(pa, pb);
	}
	
	return pb;
}
int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>x;
	
	for(b=0;b<65;b++)
	{
		if(((long long)1<<b) > x)
		{
			b--;
			y=((long long)1 << b) * x;
			mul(x, ((long long)1 << b));
			ans.push_back(pos(x, y, 1));
			y^=x;
			
			//cout<<x<<' '<<y<<'\n';
			break;
		}
	}
	
	auto coef=euclidExtins(x, y);
	coef.second*=-1;
	
	
	while(coef.first<=0 || coef.second<=0)
	{
		coef.first+=y;
		coef.second+=x;
	}
	
	if(coef.second%2)
	{
		coef.first+=y;
		coef.second+=x;
	}
	
	
	mul(x, coef.first);
	mul(y, coef.second);
	
	x*=coef.first;
	y*=coef.second;
	
	ans.push_back(pos(x, y, 1));
	
	cout<<ans.size()<<'\n';
	for(auto it : ans)
	{
		cout<<it.x;
		
		if(it.t==1)
			cout<<" ^ ";
		else
			cout<<" + ";
			
		cout<<it.y<<'\n';
	}
	return 0;
}

