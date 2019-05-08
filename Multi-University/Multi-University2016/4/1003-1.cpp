#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=25;
const int maxm=1000;

int head[maxn],point[maxm],nxt[maxm],val[maxm],size;
int col[maxn];
int n,m;
int ans;

void init(){
	ans=1000000;
	size=0;
	memset(head,-1,sizeof(head));
	memset(val,0,sizeof(val));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}


void dfs(int s){
	if(s==n){
		int tmp=0;
		for(int i=0;i<n;++i){
			for(int k=head[i];~k;k=nxt[k]){
				int j=point[k];
				if(col[i]!=col[j])tmp++;
			}
		}
		if(tmp==ans&&tmp!=0){
			for(int i=0;i<n;++i){
				for(int k=head[i];~k;k=nxt[k]){
					int j=point[k];
					if(col[i]!=col[j])val[k]++;
				}
			}
		}
		else if(tmp<ans&&tmp!=0){
			memset(val,0,sizeof(val));
			for(int i=0;i<n;++i){
				for(int k=head[i];~k;k=nxt[k]){
					int j=point[k];
					if(col[i]!=col[j])val[k]++;
				}
			}
			ans=tmp;
		}
		return;
	}
	col[s]=1;
	dfs(s+1);
	col[s]=0;
	dfs(s+1);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		init();
		scanf("%d%d",&n,&m);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		col[0]=0;
		dfs(1);
		printf("Case #%d:",q);
		for(int i=0;i<size;i+=2){
			printf(" %d",val[i]);
		}
		printf("\n");
	}
	return 0;
}
