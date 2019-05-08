#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MAXM=1000000;
struct cmp{
	bool operator ()(pii a,pii b){
		return a.first>b.first;
	}
};

int head1[MAXM+5],point1[MAXM+5],val1[MAXM+5],next1[MAXM+5],size1;
int head2[MAXM+5],point2[MAXM+5],val2[MAXM+5],next2[MAXM+5],size2;
int n,m;
ll dist1[MAXM+5],dist2[MAXM+5];

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
	for(i=head2[a];~i;i=next2[i]){
		if(point2[i]==b){
			if(val2[i]>v)val2[i]=v;
			return;
		}
	}
	point2[size2]=b;
	val2[size2]=v;
	next2[size2]=head2[a];
	head2[a]=size2++;
}

void dij(int s){
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	memset(dist1,-1,sizeof(dist1));
	memset(dist2,-1,sizeof(dist2));
	dist1[s]=dist2[s]=0;
	q.push(make_pair(dist1[s],s));
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dist1[u.second])continue;
		for(i=head1[u.second];~i;i=next1[i]){
			int j=point1[i];
			if(dist1[j]==-1||dist1[j]>dist1[u.second]+val1[i]){
				dist1[j]=dist1[u.second]+val1[i];
				q.push(make_pair(dist1[j],j));
			}
		}
	}
	while(!q.empty())q.pop();
	q.push(make_pair(dist2[s],s));
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dist2[u.second])continue;
		for(i=head2[u.second];~i;i=next2[i]){
			int j=point2[i];
			if(dist2[j]==-1||dist2[j]>dist2[u.second]+val2[i]){
				dist2[j]=dist2[u.second]+val2[i];
				q.push(make_pair(dist2[j],j));
			}
		}
	}
	ll ans=0;
	for(i=1;i<=n;i++){
		ans+=dist1[i];
		ans+=dist2[i];
	}
	printf("%I64d\n",ans);
}

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			scanf("%d%d",&n,&m);
			int i,a,b,v;
			memset(head1,-1,sizeof(head1));
			size1=0;
			memset(head2,-1,sizeof(head2));
			size2=0;
			for(i=1;i<=m;i++){
				scanf("%d%d%d",&a,&b,&v);
				add1(a,b,v);
				add2(b,a,v);
			}
			dij(1);
		}
	}
	return 0;
}
