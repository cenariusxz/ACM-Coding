#include<stdio.h>
#include<string.h>

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int head[105],point[105],nxt[105],size=0;
int ans;
int stx[1000],edx[1000],t;
bool f[105];
int n,k;

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void dfs(int o){
	stx[o]=++t;
	int i;
	for(i=head[o];i!=-1;i=nxt[i]){
		dfs(point[i]);
	}
	edx[o]=t;
	if(edx[o]-stx[o]==k)ans++;
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		ans=0;
		memset(head,-1,sizeof(head));
		memset(f,0,sizeof(f));
		t=0;
		size=0;
		int i;
		for(i=1;i<=n-1;i++){
			int a=read();
			int b=read();
			add(a,b);
			f[b]=1;
		}
		for(i=1;i<=n;i++){
			if(f[i]==0){
				dfs(i);
				break;
			}
		}
//		for(i=1;i<=n;i++)printf("%d %d\n",stx[i],edx[i]);
		printf("%d\n",ans);

	}
	return 0;
}
