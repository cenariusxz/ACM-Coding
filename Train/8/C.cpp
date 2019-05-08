#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=4e4;

int head[maxn],point[maxn],nxt[maxn],size;
int n;
ll ans=0;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

int dfs(int s,int fa){
	ll sum1=n-1,sum2=0,ss=0;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j!=fa){
			int k=dfs(j,s);
			ss+=k;
			sum2+=k*(ll)k;
		}
	}
	sum2+=(n-ss-1)*(ll)(n-ss-1);
	ll res=(sum1*sum1-sum2)>>1;
	if(res>ans)ans=res;
	return ss+1;
}

int main(){
	int T;
	scanf("%d",&T);
	int cnt=0;
	while(T--){
		ans=0;
		scanf("%d",&n);
		init();
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		dfs(1,-1);
		printf("Case #%d: ",++cnt);
		printf("%lld\n",ans);

	}
	return 0;
}
