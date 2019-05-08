#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

int a[maxn];
int l[maxn],r[maxn];
int c[maxn];
int n;

void init(){
	memset(c,0,sizeof(c));
}

inline int lowbit(int x){return x&(-x);}

void add(int x){
	for(int i=x;i<=n;i+=lowbit(i))c[i]++;
}

int sum(int x){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			l[a[i]]=min(a[i],i);
			r[a[i]]=max(a[i],i);
		}
		init();
		int maxx=-1;
		for(int i=n;i>=1;--i){
			add(a[i]);
			int num=sum(a[i]-1);
			if(i+num>r[a[i]])r[a[i]]=i+num;
			if(i+num<l[a[i]])l[a[i]]=i+num;
			if(a[i]>maxx){
				maxx=a[i];
				r[a[i]]=n;
			}
		}
		printf("Case #%d:",q);
		for(int i=1;i<=n;++i)printf(" %d",r[i]-l[i]);
		printf("\n");
	}

	return 0;
}
