#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int c[100005];
int n,m,num[2];
int head[100005],nxt[200005],point[200005],size=0;
bool f=0;

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
	scanf("%d%d",&n,&m);
	if(m==0){
		ll ans=(ll)n*(ll)(n-1)*(ll)(n-2)/6;
		printf("3 %I64d\n",ans);
		return 0;
	}
	int i;
	memset(head,-1,sizeof(head));
	memset(c,-1,sizeof(c));
	for(i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	ll ans=0,ans2=0;
	for(i=1;i<=n&&(!f);i++){
		if(c[i]==-1){
			num[0]=num[1]=0;
			dfs(i,1);
			ans+=(ll)num[0]*(ll)(num[0]-1)/2;
			ans+=(ll)num[1]*(ll)(num[1]-1)/2;
			if(num[0]==1&&num[1]==1){
				ans2+=n-2;
			}
		}
	}
	if(f)printf("0 1\n");
	else if(ans==0)printf("2 %I64d\n",ans2);
	else printf("1 %I64d\n",ans);
	return 0;
}
