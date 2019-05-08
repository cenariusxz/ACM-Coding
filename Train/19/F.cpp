#include<bits/stdc++.h>
#define MAXN 1000010
using namespace std;
struct node{
	int to,next,index;
}edge[MAXN];
int tot,head[MAXN];
int n,m;
int s,t,st,tt;
long long S,T;
int from[MAXN],to[MAXN],t1[MAXN],t2[MAXN];
int pre[MAXN];
long long from1[MAXN],to1[MAXN];
bool vis[MAXN]={0};
vector<long long> v;
map<long long ,int> mp;
int qu[MAXN],front,tail;
int sta[MAXN],top;
vector<long long> sst[MAXN];

inline int scan()
{
	int res=0,ch;
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res;
}

void addedge(int x,int y,int z)
{
	//printf(" %d %d\n",x,y);
	++tot;
	edge[tot].to=y;
	edge[tot].next=head[x];
	edge[tot].index=z;
	head[x]=tot;
}

int main()
{
	bool f=0;
	int i;
	tot=0;
	memset(head,-1,sizeof(head));
	n=scan();m=scan();
	//scanf("%d%d",&n,&m);
	for(i=1;i<=m+1;i++){
		from[i]=scan();to[i]=scan();t1[i]=scan();t2[i]=scan();
		//scanf("%d%d%d%d",&from[i],&to[i],&t1[i],&t2[i]);
		from1[i]=from[i]*10000000ll+t1[i];
		to1[i]=to[i]*10000000ll+t2[i];
		v.push_back(from1[i]);
		v.push_back(to1[i]);
		sst[from[i]].push_back(t1[i]);
		sst[to[i]].push_back(t2[i]);
	}
	s=from[m+1];t=to[m+1];st=t1[m+1];tt=t2[m+1];
	sort(v.begin(),v.end());
	vector<long long>::iterator iter=unique(v.begin(),v.end()); 
    v.erase(iter,v.end()); 
	for(i=0;i<v.size();i++)
		mp[v[i]]=i+1;
	for(i=1;i<=m;i++){
		from1[i]=mp[from1[i]];
		to1[i]=mp[to1[i]];
		addedge(from1[i],to1[i],i);
	}
	int index=1;
	for(i=1;i<=n;i++){
		if(sst[i].size()==0||sst[i].size()==1){
			index+=sst[i].size();
			continue;
		}
		sort(sst[i].begin(),sst[i].end());
		unique(sst[i].begin(),sst[i].end());
		vector<long long>::iterator iter=unique(sst[i].begin(),sst[i].end()); 
   		sst[i].erase(iter,sst[i].end()); 
		for(int j=0;j<sst[i].size()-1;++j){
			int From=index+j;
			int To=index+j+1;
			addedge(From,To,tot+1);
			from1[tot]=From;
			to1[tot]=To;
		}
		index+=sst[i].size();
	}
	S=mp[s*10000000ll+st];
	T=mp[t*10000000ll+tt];
	front=0;tail=1;
	qu[0]=S;
	vis[S]=1;
	while(front<tail){
		int now=qu[front++];
		if(now==T){
			f=1;
			break;
		}
		for(i=head[now];~i;i=edge[i].next){
			if(vis[edge[i].to]) continue;
			pre[edge[i].to]=edge[i].index;
			vis[edge[i].to]=1;
			qu[tail++]=edge[i].to;
		}
	}
	if(f==0){
		printf("Impossible\n");
		return 0;
	}
	top=-1;
	int p=T;
	while(p!=S){
		if(pre[p]<=m) sta[++top]=pre[p];
		p=from1[pre[p]];
	}
	printf("%d\n",top+1);
	while(top!=-1){
		printf("%d",sta[top--]);
		if(top!=-1) printf(" ");
	}
	printf("\n");
 return 0;
}
