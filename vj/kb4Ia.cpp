#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<vector>
using namespace std;

int head[35],nxt[1000],point[1000],size;
double val[1000],dist[35];
bool vis[35];
int n,p,t[35];

void add(int a,int b,double v){
	int i;
	for(i=head[a];~i;i=nxt[i]){
		if(point[i]==b){
			if(val[i]<v)val[i]=v;
			return;
		}
	}
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

void spfa(){
	int i;
	memset(dist,0,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(t,0,sizeof(t));
	dist[1]=100;
	vis[1]=1;
	queue<int>q;
	q.push(1);
	bool f=1;
	while(!q.empty()&&f){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(i=head[u];~i;i=nxt[i]){
			int j=point[i];
			double v=dist[u]*val[i];
			if(dist[j]<v){
				dist[j]=v;
				if(!vis[j]){
					q.push(j);
					vis[j]=1;
					t[j]++;
					if(t[j]>n)f=0;
				}
			}
		}
	}
	if(f)printf("Case %d: No\n",++p);
	else printf("Case %d: Yes\n",++p);
}

int main(){
	p=0;
	while(scanf("%d",&n)!=EOF&&n!=0){
		map<string,int>M;
		int i;
		string tmp;
		memset(head,-1,sizeof(head));
		size=0;
		for(i=1;i<=n;i++){
			cin>>tmp;
			M[tmp]=i;
		}
		int m;
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			string t1,t2;
			double a;
			cin>>t1>>a>>t2;
			add(M[t1],M[t2],a);
		}
		spfa();
	}
	return 0;
}
