#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=3e6+5;
int n;
int a[maxn];
int c[maxn];

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
	int T,cnt=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		int ans=0;
		for(int i=n;i>=1;--i){
			if(sum(a[i]))ans++;
			add(a[i]);
		}
		printf("Case #%d: %d\n",++cnt,ans);
	}
	return 0;
}
