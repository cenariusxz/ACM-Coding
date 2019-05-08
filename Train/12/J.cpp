#include<stdio.h>
#include<string.h>
using namespace std;

const int maxn=105;
const int maxm=1e4+5;

int num[maxn];
int head[maxn],point[maxm],nxt[maxm],size;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i){
			scanf("%d",&num[i]);
		}
		init();
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		int ans=0;
		int pre=0;
		while(1){
			ans+=num[pre];
			int now=-1;
			for(int i=head[pre];~i;i=nxt[i]){
				int j=point[i];
				if(now==-1||num[j]>num[now]){
					now=j;
				}
			}
			if(now==-1)break;
			pre=now;
		}
		printf("Case %d: %d %d\n",q,ans,pre);
	}
}
