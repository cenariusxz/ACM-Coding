#include<stdio.h>
#include<string.h>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],point[maxm],nxt[maxm],size;
int n,t,bcccnt;							
//n点数，t是dfs的时间轴，bcccnt是双连通分量个数
int stx[maxn],low[maxn],bcc[maxn],cut[maxn];	
//stx是节点在dfs时间轴的位置，low是该点能够通过后继节点到达的最远祖先，bcc是某个点所属的双连通分量编号（割点的编号无效），cut是是否为割点
vector<int>bccs[maxn];
//双连通分量内的节点
stack<int>S;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void dfs(int s,int pre){
	stx[s]=low[s]=++t;		//记录点的时间轴标号，初始化能访问到的最远祖先节点是自己
	S.push(s);
	int son=0;				//为了判定根节点是否是割点
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!stx[j]){
			son++;
			dfs(j,s);
			low[s]=min(low[s],low[j]);	//用子节点的low值更新自己
			if(low[j]>=stx[s]){			//如果子节点最远只能访问自己或后继节点，则出现双连通分量
				cut[s]=1;				//自己是割点
				bcccnt++;
				bccs[bcccnt].clear();
				while(1){
					int u=S.top();S.pop();
					bcc[u]=bcccnt;
					bccs[bcccnt].push_back(u);
					if(u==j)break;
				}
				bcc[s]=bcccnt;
				bccs[bcccnt].push_back(s);
			}
		}
		else if(j!=pre)low[s]=min(stx[j],low[s]);
	}
	if(pre==-1&&son==1)cut[s]=0;		//若根节点只有一个子节点，则不是割点
}

void setbcc(){
	memset(cut,0,sizeof(cut));
	memset(stx,0,sizeof(stx));
	memset(bcc,0,sizeof(bcc));
	t=bcccnt=0;
	for(int i=1;i<=n;++i)if(!stx[i])dfs(i,-1);
}

int main(){
	int m;
	scanf("%d%d",&n,&m);
	init();
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	setbcc();
	for(int i=1;i<=n;++i){
		printf("%d:%d %d\n",i,cut[i],bcc[i]);
	}
	for(int i=1;i<=bcccnt;++i){
		printf("%d:",i);
		for(int j=0;j<bccs[i].size();++j){
			printf("%d ",bccs[i][j]);
		}
		printf("\n");
	}
	return 0;
}
