#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int p[5],m[5],t[5],G[5],B[5];
int vis[5][5];
int ans=0;

void dfs(int);

void get1(int s,int num){
	vis[s][1]=1;
	int tmp=p[s];
	int minn=min(p[1],min(p[2],p[3]));
	int maxx=max(p[1],max(p[2],p[3]));
	if(maxx==p[s]){
		int nxt=tmp+m[s];
		p[s]=nxt;
		ans=max(ans,p[s]);
		dfs(num+1);
		p[s]=tmp;
	}
	else{
		int lim=-m[s];
		if(minn==p[s])lim=1;
		for(int i=lim;i<=m[s];++i){
			int nxt=tmp+i;
			if(nxt>=1&&p[1]!=nxt&&p[2]!=nxt&&p[3]!=nxt){
				p[s]=nxt;
				ans=max(ans,p[s]);
				dfs(num+1);
				p[s]=tmp;
			}
		}
	}
	vis[s][1]=0;
}

void get2(int s,int num){
	vis[s][2]=1;
	for(int id=1;id<=3;++id){
		if(id==s)continue;
		if(!B[id]&&(p[id]==p[s]+1||p[id]==p[s]-1)){
			int tmp=p[id];
			p[id]=p[s];
			if(G[id])p[G[id]]=p[id];
			G[s]=id;
			B[id]=s;
			dfs(num+1);
			G[s]=0;
			B[id]=0;
			p[id]=tmp;
			if(G[id])p[G[id]]=p[id];
		}
	}
	vis[s][2]=0;
}

void get3(int s,int num){
	vis[s][3]=1;
	int tmp=p[s];
	int id=G[s];
	int minn=min(p[1],min(p[2],p[3]));
	int lim=-t[s];
	if(minn==p[s])lim=1;
	for(int i=lim;i<=t[s];++i){
		int nxt=tmp+i;
		if(nxt>=1&&p[1]!=nxt&&p[2]!=nxt&&p[3]!=nxt){
			p[id]=nxt;
			ans=max(ans,p[id]);
			if(G[id])p[G[id]]=p[id];
			G[s]=0;
			B[id]=0;
			dfs(num+1);
			G[s]=id;
			B[id]=s;
			p[id]=tmp;
			if(G[id])p[G[id]]=p[id];
		}
	}
	vis[s][3]=0;
}

void dfs(int num){
	if(num==9)return;
	for(int i=1;i<=3;++i){
		if(B[i])continue;
		else if(G[i])get3(i,num);
		else{
			if(!vis[i][1])get1(i,num);
			if(!vis[i][2])get2(i,num);
		}
	}
}

int main(){
	for(int i=1;i<=3;++i)scanf("%d%d%d",&p[i],&m[i],&t[i]);
	ans=max(p[1],max(p[2],p[3]));
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
