#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x,y,s;
};
queue<node> q;

int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};
int n,m,k;
int second;
bool used[1010][1010];

void print()
{
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(used[i][j]==1) sum++;
	printf("%d ",sum);
}

void bfs()
{
	while(!q.empty())
	{
		node p=q.front();
		q.pop();
		if(p.s==second)
		{
			//cout<<"second:"<<p.x<<" "<<p.y<<" "<<p.s<<endl;
			print();
			second++;
		}
		for(int i=0;i<4;i++)
		{
			int dx = p.x+xx[i];
			int dy = p.y+yy[i];
			//cout<<"dx:"<<dx<<"dy:"<<dy<<endl;
			if(dx<1 || dy<1 || dx>n || dy>m) continue;
			if(used[dx][dy]) continue;
			//cout<<"ok"<<endl;
			used[dx][dy]=1;
			q.push(node{dx,dy,p.s+1});
		}
	}
	exit(0);
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		used[x][y]=1;
		q.push(node{x,y,1});
	}
	second=2;
	print();
	bfs();
    return 0;
}
