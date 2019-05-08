#include<stdio.h>	//需要这些头文件
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

//maxn为点总数，maxm为边总数（原图）
const int maxn=1005;
const int maxm=6005;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];	//0是原图，1是缩点后的图
int n,t,scccnt;		//n为点数，t是时间轴，scccnt是强连通分量数
int stx[maxn],low[maxn],scc[maxn];	//stx是点的时间轴标号，low是能达到的最远祖先节点，scc是点所属强连通分量编号
stack<int>S;	//用来存强连通分量内的点，并最后依次加入强连通分量

void init(){	//原图的初始化
	memset(head,-1,sizeof(head));
	size[0]=size[1]=0;
}

void add(int a,int b,int c=0){		//加边函数，原图是0，建原图时可以不传入参数c，缩点图是1
	point[c][size[c]]=b;
	nxt[c][size[c]]=head[c][a];
	head[c][a]=size[c]++;
}

void dfs(int s){
	stx[s]=low[s]=++t;		//节点的时间轴标号，其能访问的起始最远祖先是它自己
	S.push(s);				//将s点压入栈
	for(int i=head[0][s];~i;i=nxt[0][i]){
		int j=point[0][i];
		if(!stx[j]){		//如果j还没有被访问过，就说明不存在与之前已经定的强连通分量中，就从此点继续搜索
			dfs(j);
			low[s]=min(low[s],low[j]);	//用后继点更新自己能到达的最远祖先
		}
		else if(!scc[j]){	//如果scc[j]已经有值，说明j已经是其他强连通分量中的点，那么对它 dfs 时没有搜索到s点说明s点和j点不在同一强连通分量中，所以不需要处理
			low[s]=min(low[s],stx[j]);
		}
	}
	if(low[s]==stx[s]){		//自己及后继能访问的最远祖先就是自己，那么从这之后的所有点都是这个强连通分量的点，从栈中取出点依次标记
		scccnt++;
		while(1){
			int u=S.top();S.pop();
			scc[u]=scccnt;
			if(s==u)break;
		}
	}
}

void setscc(){
	memset(stx,0,sizeof(stx));
	memset(scc,0,sizeof(scc));
	t=scccnt=0;
	for(int i=1;i<=n;++i)if(!stx[i])dfs(i);	//依次dfs
	for(int i=1;i<=n;++i){
		for(int j=head[0][i];~j;j=nxt[0][j]){
			int k=point[0][j];
			if(scc[i]!=scc[k]){			//两点不在同一个强连通分量中，那么这两个强连通分量就继承两点的有向边。
				add(scc[i],scc[k],1);
			}
		}
	}
}

