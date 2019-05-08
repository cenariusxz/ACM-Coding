#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxm=1006;

int head[maxm],point[maxm<<1],nxt[maxm<<1],size;
int d[maxm];
int dl[maxm];
int maxx=0;

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

int dfs(int a,int l){
	d[a]=l;
	if(l>maxx)maxx=l;
	dl[l]++;
	for(int i=head[a];~i;i=nxt[i]){
		int j=point[i];
		if(d[j])continue;
		else dfs(j,l+1);
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(head,-1,sizeof(head));
		memset(d,0,sizeof(d));
		memset(dl,0,sizeof(dl));
		size=0;
		maxx=0;
		for(int i=1;i<=n-1;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		dfs(1,1);
		bool f=1;
		bool ff=0;
		for(int i=1;i<maxx&&f;++i)if(dl[i]>1)f=0;
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
