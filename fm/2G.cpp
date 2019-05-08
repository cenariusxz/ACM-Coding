#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=1005*2;
const int maxm=110005;

int id[3][maxn],n;
int num[3][maxn];
int head[3][maxn],point[3][maxm],nxt[3][maxm],size[3];
char s[5];

void add(int a,int b,int c){
	point[c][size[c]]=b;
	nxt[c][size[c]]=head[c][a];
	head[c][a]=size[c]++;
	id[c][b]++;
}

bool topo(int c){
	queue<int>q;
	for(int i=1;i<=2*n;++i)if(!id[c][i])q.push(i);
	int cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		num[c][u]=++cnt;
		for(int i=head[c][u];~i;i=nxt[c][i]){
			int j=point[c][i];
			id[c][j]--;
			if(!id[c][j])q.push(j);
		}
	}
	if(cnt==2*n)return 1;
	return 0;
}

int main(){
	int cnt=0,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		memset(head,-1,sizeof(head));
		memset(size,0,sizeof(size));
		memset(id,0,sizeof(id));
		for(int i=1;i<=n;++i){
			add(2*i-1,2*i,0);
			add(2*i-1,2*i,1);
			add(2*i-1,2*i,2);
		}
		while(m--){
			int a,b;
			scanf("%s%d%d",s,&a,&b);
			if(s[0]=='X')add(2*a,2*b-1,0);
			else if(s[0]=='Y')add(2*a,2*b-1,1);
			else if(s[0]=='Z')add(2*a,2*b-1,2);
			else if(s[0]=='I'){
				add(2*a-1,2*b,0);
				add(2*a-1,2*b,1);
				add(2*a-1,2*b,2);
				add(2*b-1,2*a,0);
				add(2*b-1,2*a,1);
				add(2*b-1,2*a,2);
			}
		}
		printf("Case %d: ",++cnt);
		if(!topo(0))printf("IMPOSSIBLE\n");
		else if(!topo(1))printf("IMPOSSIBLE\n");
		else if(!topo(2))printf("IMPOSSIBLE\n");
		else{
			printf("POSSIBLE\n");
			for(int i=1;i<=n;++i){
				printf("%d %d %d %d %d %d\n",num[0][2*i-1],num[1][2*i-1],num[2][2*i-1],num[0][2*i],num[1][2*i],num[2][2*i]);
			}
		}
		printf("\n");
	}
	return 0;
}
