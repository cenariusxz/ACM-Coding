#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB puss_back
#define MP make_pair
const double eps=1e-8;
const int INF=0*3;
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxm=1e6+6;

struct node
{
	int x,y;
};
int n,m,ans=0;
char a[110][110];
int xx[8]={-1,-1,-1,0,0,1,1,1};
int yy[8]={-1,0,1,-1,1,-1,0,1};
void bfs(int x,int y)
{
	queue<node> q;
	q.push(node{x,y});
	a[x][y]='.';
	while (!q.empty())
	{
		node u=q.front();
		q.pop();
		for (int i=0;i<8;i++)
		{
			int dx=u.x+xx[i];
			int dy=u.y+yy[i];
			if (dx<1||dx>n||dy<1||dy>m) continue;
			if (a[dx][dy]=='.') continue;
			q.push(node{dx,dy});
			a[dx][dy]='.';
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]=='W') 
			{
				ans++;
				bfs(i,j);
			}
	cout<<ans;
	return 0;
}
