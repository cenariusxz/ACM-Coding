#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct T{
	int l,r;
	bool operator<(const T x)const{
		if(r==x.r)return l<x.l;
		return r<x.r;
	}
}p[25];

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int a,b,cnt=0;
		while(1){
			scanf("%d%d",&a,&b);
			if(a==0&&b==0)break;
			cnt++;
			p[cnt].l=a;
			p[cnt].r=b;
		}
		sort(p+1,p+cnt+1);
		int pre=0;
		int ans=0;
		for(int i=1;i<=cnt;++i){
			if(p[i].l>=pre){
				ans++;
				pre=p[i].r;
			}
		}
		printf("%d\n",ans);
	}
}
