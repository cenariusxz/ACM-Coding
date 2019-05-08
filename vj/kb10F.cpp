#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=3005;//最大点数
const int INF=0x3f3f3f3f;//距离初始值
int Map[MAXN][MAXN];//二分图
int cx[MAXN];//cx[i]表示左集合i顶点所匹配的右集合的顶点序号
int cy[MAXN];//cy[i]表示右集合i顶点所匹配的左集合的顶点序号
int n,m,dis;
int dx[MAXN],dy[MAXN];
bool vis[MAXN];
int xp[3005],yp[3005],s[3005];
int xu[3005],yu[3005];

bool searchpath(){
	queue<int>Q;
	dis=INF;
	memset(dx,-1,sizeof(dx));
	memset(dy,-1,sizeof(dy));
	for(int i=1;i<=n;++i){
		//cx[i]表示左集合i顶点所匹配的右集合的顶点序号
		if(cx[i]==-1){
			//将未遍历的节点入队并初始化次节点距离为0
			Q.push(i);
			dx[i]=0;
		}
	}
	//广度搜索增广路径
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		if(dx[u]>dis)break;
		//取右侧节点
		for(int i=1;i<=m;++i){
			//右侧节点的增广路径的距离
			if(Map[u][i]&&dy[i]==-1){
				dy[i]=dx[u]+1;//v对应的距离为u对应距离加1
				if(cy[i]==-1)dis=dy[i];
				else{
					dx[cy[i]]=dy[i]+1;
					Q.push(cy[i]);
				}
			}
		}
	}
	return dis!=INF;
}

//寻找路径深度搜索
int findpath(int s){
	for(int i=1;i<=m;++i){
		//如果该点没有被遍历过并且距离为上一节点+1
		if(!vis[i]&&Map[s][i]&&dy[i]==dx[s]+1){
			//对该点染色
			vis[i]=1;
			if(cy[i]!=-1&&dy[i]==dis)continue;
			if(cy[i]==-1||findpath(cy[i])){
				cy[i]=s;cx[s]=i;
				return 1;
			}
		}
	}
	return 0;
}

//得到最大匹配的数目
int MaxMatch(){
	int res=0;
	memset(cx,-1,sizeof(cx));
	memset(cy,-1,sizeof(cy));
	while(searchpath()){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			if(cx[i]==-1)res+=findpath(i);
		}
	}
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		memset(Map,0,sizeof(Map));
		int t;
		scanf("%d",&t);
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&xp[i],&yp[i],&s[i]);
		}
		scanf("%d",&m);
		for(int i=1;i<=m;++i){
			scanf("%d%d",&xu[i],&yu[i]);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if((xp[i]-xu[j])*(ll)(xp[i]-xu[j])+(yp[i]-yu[j])*(ll)(yp[i]-yu[j])<=t*(ll)t*s[i]*s[i]){
					Map[i][j]=1;
				}
			}
		}
		printf("Scenario #%d:\n%d\n\n",q,MaxMatch());
	}
	return 0;
}
