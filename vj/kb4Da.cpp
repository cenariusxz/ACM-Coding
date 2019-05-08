#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXM=100000;
typedef pair<int,int> pii;

int head1[1005],next1[MAXM+5],point1[MAXM+5],val1[MAXM+5],size1,dist1[1005];
int head2[1005],next2[MAXM+5],point2[MAXM+5],val2[MAXM+5],size2,dist2[1005];
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

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

void dij(int s){
	int i;
	memset(dist1,-1,sizeof(dist1));
	dist1[s]=0;
	priority_queue<pii,vector<pii>,cmp>q1;
	q1.push(make_pair(dist1[s],s));
	while(!q1.empty()){
		pii u=q1.top();
		q1.pop();
		if(u.first>dist1[u.second])continue;
		for(i=head1[u.second];~i;i=next1[i]){
			int j=point1[i];
			if(dist1[j]==-1||dist1[j]>u.first+val1[i]){
				dist1[j]=u.first+val1[i];
				q1.push(make_pair(dist1[j],j));
			}
		}
	}
	memset(dist2,-1,sizeof(dist2));
	dist2[s]=0;
	priority_queue<pii,vector<pii>,cmp>q2;
	q2.push(make_pair(dist2[s],s));
	while(!q2.empty()){
		pii u=q2.top();
		q2.pop();
		if(u.first>dist2[u.second])continue;
		for(i=head2[u.second];~i;i=next2[i]){
			int j=point2[i];
			if(dist2[j]==-1||dist2[j]>u.first+val2[i]){
				dist2[j]=u.first+val2[i];
				q2.push(make_pair(dist2[j],j));
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++){
		if(dist1[i]+dist2[i]>ans){
			ans=dist1[i]+dist2[i];
		}
	}
	printf("%d\n",ans);
}

int main(){
	int m,s;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF){
		int i;
		memset(head1,-1,sizeof(head1));
		memset(head2,-1,sizeof(head2));
		size1=0;
		size2=0;
		for(i=1;i<=m;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add1(a,b,v);
			add2(a,b,v);
		}
		dij(s);
	}
}
