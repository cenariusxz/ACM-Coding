#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;

const int maxn=1e3+5;
const int maxm=1e6+5;

int head[maxn],point[maxm],nxt[maxm],size;
int match[maxn],vis[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(match,-1,sizeof(match));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

int dfs(int s){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j]){
			vis[j]=1;
			if(match[j]==-1||dfs(match[j])){
				match[j]=s;
				return 1;
			}
		}
	}
	return 0;
}

string like[505],dislike[505];
int col[505];
char s1[55],s2[55];

int main(){
	int n,m,p;
	while(scanf("%d%d%d",&n,&m,&p)!=EOF){
		init();
		for(int i=1;i<=p;++i){
			scanf("%s%s",s1,s2);
			if(s1[0]=='C')col[i]=1;
			else col[i]=0;
			like[i]=string(s1);
			dislike[i]=string(s2);
		}
		for(int i=1;i<=p;++i){
			if(!col[i])continue;
			for(int j=1;j<=p;++j){
				if(col[j])continue;
				if(like[i]==dislike[j]||like[j]==dislike[i])add(i,j);
			}
		}
		int ans=0;
		for(int i=1;i<=p;++i){
			if(!col[i])continue;
			memset(vis,0,sizeof(vis));
			if(dfs(i)==1)ans++;
		}
		printf("%d\n",p-ans);
	}
	return 0;
}
