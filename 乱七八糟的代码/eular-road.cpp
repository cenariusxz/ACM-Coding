#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1005;		//点数
const int maxm=1005*26;		//边数
int head[maxn],size;
int point[maxm],nxt[maxm],vis[maxm],ind[maxm];
int id[maxn],od[maxn];
int cnt;
int ans[maxm];
void init(){
	cnt=size=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(id,0,sizeof(id));
	memset(od,0,sizeof(od));
}
void adde(int a,int b,int index){
	point[size]=b;
	ind[size]=index;
	nxt[size]=head[a];
	head[a]=size++;
	od[a]++;id[b]++;
}
void dfs(int s){
	for(int i=head[s];~i;i=nxt[i]){
		if(!vis[i]){
			vis[i]=1;
			dfs(point[i]);
			ans[cnt++]=ind[i];
		}
	}
}
//边数较多的图中可能重复遍历已经访问过的边会T，访问一条边直接删一条边可以更加快速
/*
void dfs(int s){
	while(~head[s]){
		int i=head[s];
		head[s]=nxt[i];
		dfs(point[i]);
		ans[cnt++]=ind[i];
	}
}
*/
void solve(int n,int m){		//n点m边
	int c1=0,c2=0,stx=1;		//stx取标号最小的节点
	for(int i=1;i<=n;i++){
		if(od[i]-id[i]==1)c1++,stx=i;
		else if(od[i]-id[i]==-1)c2++;
		else if(od[i]-id[i]!=0)c1=3;
	}
	if(!((c1==0&&c2==0)||(c1==1&&c2==1))){
		printf("NO\n");
		return;
	}
	dfs(stx);
	if(cnt!=m){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(int i=cnt-1;i>=0;--i){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
	}
	return 0;
}
