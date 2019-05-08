#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
struct Edge{
	int to,next,val;
}edge[1000];
int head[1000],cnt=0;
void addedge(int a,int b,int c){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].val=c;
	edge[cnt].next=head[a];
	head[a]=cnt;
}
int n,m;
int dis[1000];
bool vis[1000];
void dij(){
	for(int i=1;i<=n;i++)
		vis[i]=false,dis[i]=INF;

	dis[1]=0;

	for(int t=1;t<=n;t++){
		int Min=INF,Note=-1;
		for(int i=1;i<=n;i++)
			if(!vis[i] && dis[i]<Min){Min=dis[i];Note=i;}
		cout<<"sss : "<<Note<<endl;
		if(Note==-1)	break;
		vis[Note]=true;
		cout<<"bbb "<<Note<<" "<<head[Note]<<endl;
		for(int i=head[Note];i!=-1;i=edge[i].next){
            cout<<"aaa "<<Note<<"->"<<edge[i].to<<"  :  "<<dis[edge[i].to]<<" "<<dis[Note] + edge[i].val<<endl;
			dis[edge[i].to]=min(dis[Note]+edge[i].val,dis[edge[i].to]);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<"1 -> "<<i<<" : "<<dis[i]<<endl;
}
int main(){
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		addedge(a,b,c);
		addedge(b,a,c);
	}
	for(int i=1;i<=n;i++){
		for(int j=head[i];j!=-1;j=edge[j].next){
			cout<<i<<" -> "<<edge[j].to<<" "<<edge[j].val<<endl;
		}
	}
	dij();
	return 0;
}
