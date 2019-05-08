#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

const int maxn=1e5+5;

struct node{
	char c;
	int x,y,z;
};

int top[maxn],bot[maxn];
int len[maxn];
int head[maxn],point[maxn<<2],nxt[maxn<<2],size;

void init(){
	size=0;
	memset(head,-1,sizeof(head));
	memset(top,-1,sizeof(top));
	memset(bot,-1,sizeof(bot));
	memset(len,-1,sizeof(len));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

int dfs(int s){
	if(len[s]!=-1)return len[s];
	len[s]=0;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		int l=dfs(j);
		len[s]=max(len[s],l+1);
	}
	return len[s];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n,k;
		scanf("%d%d",&n,&k);
		init();
		top[1]=top[n]=0;
		bot[1]=bot[n]=1;
		queue<node>q1;
		int cnt=1;
		while(k--){
			char s[11];
			node tmp;
			scanf("%s%d%d%d",s,&tmp.x,&tmp.y,&tmp.z);
			tmp.c=s[0];
			q1.push(tmp);
		}
		while(!q1.empty()){
			node u=q1.front();
			q1.pop();
			if(u.c=='F'){
				if(top[u.x]==-1||bot[u.x]==-1){
					q1.push(u);
				}
				else{
					top[u.y]=top[u.x];
					bot[u.z]=bot[u.x];
					bot[u.y]=top[u.z]=++cnt;
					add(top[u.y],bot[u.y]);
					add(top[u.z],bot[u.z]);
				}
			}
			else{
				if(top[u.x]==-1||bot[u.y]==-1){
					q1.push(u);
				}
				else{
					top[u.z]=top[u.x];
					bot[u.z]=bot[u.y];
				}
			}
		}
		printf("Case #%d: %d\n",q,dfs(0));
	}
	return 0;
}
