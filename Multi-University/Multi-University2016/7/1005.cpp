#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e3+5;

struct node{
	int a,num;
	bool operator < (const node x)const{
		if(a==x.a)return num>x.num;
		return a<x.a;
	}
}p[maxn];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&p[i].a);
			p[i].num=i;
		}
		sort(p+1,p+n+1);
		bool f=1;
		int sum=0;
		for(int i=1;i<=n;++i){
			if(p[i].a>i-1)f=0;
			sum+=p[i].a;
		}
		printf("Case #%d: ",q);
		if(f){
			printf("Yes\n%d\n",sum);
			for(int i=1;i<=n;++i){
				for(int j=1;j<=p[i].a;++j){
					printf("%d %d\n",p[i].num,p[j].num);
				}
			}
		}
		else printf("No\n");
	}
	return 0;
}
