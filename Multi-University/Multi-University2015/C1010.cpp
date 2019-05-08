#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct point{
	int w,num;
	bool operator<(const point a)const{
		return w>a.w;
	}
}a[500005];

int dp[500005];
int head[500005],point[1000005],nxt[1000005],size;

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,ans=0;
		memset(head,-1,sizeof(head));
		memset(dp,0,sizeof(dp));
		size=0;
		for(i=1;i<=n;i++){
			a[i].w=read();
			a[i].num=i;
		}
		for(i=1;i<n;i++){
			int a=read();
			int b=read();
			add(a,b);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			dp[a[i].num]=1;
			for(int j=head[a[i].num];~j;j=nxt[j]){
				int p=point[j];
				dp[a[i].num]+=dp[p];
			}
			if(dp[a[i].num]>ans)ans=dp[a[i].num];
		}
		printf("%d\n",ans);
	}
	return 0;	
}
