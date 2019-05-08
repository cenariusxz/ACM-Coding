#pragma comment(linker,"/STACK:16777216")
#include<stdio.h>
#include<string.h>

typedef long long ll;

int head[100005],nxt[200005],point[200005],size=0;
bool f=0;
int num[2];
int c[100005];

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void dfs(int a,int x){
	if(f)return;
	c[a]=x;
	num[x]++;
	for(int i=head[a];~i;i=nxt[i]){
		int b=point[i];
		if(c[b]==-1)dfs(b,!x);
		else if(c[b]==x){
			f=1;
			return;
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(head,-1,sizeof(head));
		size=0;
		f=0;
		memset(c,-1,sizeof(c));
		int n,m;
		scanf("%d%d",&n,&m);
		int i;
		for(i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		if(n<=1){
			printf("Poor wyh\n");
			continue;
		}
		int ans1=0,ans2=0;
		for(i=1;i<=n&&(!f);i++){
			if(c[i]==-1){
				num[0]=num[1]=0;
				dfs(i,1);
				if(num[0]>num[1]){
					ans1+=num[0];
					ans2+=num[1];
				}
				else{
					ans1+=num[1];
					ans2+=num[0];
				}
			}
		}
		if(ans2==0){ans1--;ans2++;}
		if(f)printf("Poor wyh\n");
		else printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
