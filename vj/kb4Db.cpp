#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int MAXM=100000;
int head1[1005],next1[MAXM+5],point1[MAXM+5],val1[MAXM+5],dist1[1005],size1;
bool vis1[1005];
int head2[1005],next2[MAXM+5],point2[MAXM+5],val2[MAXM+5],dist2[1005],size2;
bool vis2[1005];
int n;
void add1(int a,int b,int v){
	int i;
	for(i=head1[a];~i;i=next1[i]){
		if(point1[i]==b){
			if(val1[i]>v)val1[i]=v;
			return;
		}
	}
	point1[size1]=b;
	val1[size1]=v;
	next1[size1]=head1[a];
	head1[a]=size1++;
}

void add2(int a,int b,int v){
	int i;
	for(i=head2[b];~i;i=next2[i]){
		if(point2[i]==a){
			if(val2[i]>v)val2[i]=v;
			return;
		}
	}
	point2[size2]=a;
	val2[size2]=v;
	next2[size2]=head2[b];
	head2[b]=size2++;
}

void spfa(int s){
	int i;
	memset(dist1,-1,sizeof(dist1));
	dist1[s]=0;
	memset(vis1,0,sizeof(vis1));
	queue<int>q1;
	q1.push(s);
	vis1[s]=1;
	while(!q1.empty()){
		int u=q1.front();
		q1.pop();
		vis1[u]=0;
		for(i=head1[u];~i;i=next1[i]){
			int j=point1[i];
			if(dist1[j]==-1||dist1[j]>dist1[u]+val1[i]){
				dist1[j]=dist1[u]+val1[i];
				if(!vis1[j]){
					q1.push(j);
					vis1[j]=1;
				}
			}
		}
	}
	memset(dist2,-1,sizeof(dist2));
	dist2[s]=0;
	memset(vis2,0,sizeof(vis2));
	queue<int>q2;
	q2.push(s);
	vis2[s]=1;
	while(!q2.empty()){
		int u=q2.front();
		q2.pop();
		vis2[u]=0;
		for(i=head2[u];~i;i=next2[i]){
			int j=point2[i];
			if(dist2[j]==-1||dist2[j]>dist2[u]+val2[i]){
				dist2[j]=dist2[u]+val2[i];
				if(!vis2[j]){
					q2.push(j);
					vis2[j]=1;
				}
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++){
		if(ans<dist1[i]+dist2[i])ans=dist1[i]+dist2[i];
	}
	printf("%d\n",ans);
}

int main(){
	int m,s;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF){
		memset(head1,-1,sizeof(head1));
		size1=0;
		memset(head2,-1,sizeof(head2));
		size2=0;
		int i;
		for(i=1;i<=m;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add1(a,b,v);
			add2(a,b,v);
		}
		spfa(s);
	}
	return 0;
}
