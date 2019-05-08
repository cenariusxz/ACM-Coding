#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=1e5+5;

int num[maxn];
int sum[10];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)scanf("%d",&num[i]);
		while(q--){
			int type;
			scanf("%d",&type);
			if(type==1){
				int x,y,a;
				scanf("%d%d%d",&x,&y,&a);
				int n1=0,n2=0;
				for(int i=1;i<n;++i){
					if(num[i]==x)n1++;
					if(num[i]==y)n2++;
					if(n1>=a&&n2>=a){
						printf("%d\n",i);
						break;
					}
				}
				if(n1<a||n2<a)printf("-1\n");
			}
			else{
				int a,b;
				scanf("%d%d",&a,&b);
				for(int i=0;i<=9;++i)sum[i]=0;
				for(int i=a;i<=b;++i)sum[num[i]]++;
				int Max=-1,p;
				for(int i=0;i<=9;++i){
					if(sum[i]>Max){
						Max=sum[i];
						p=i;
					}
				}
				printf("%d\n",p);
				for(int i=a;i<=b;++i)num[i]=p;
			}
		}
	}
	return 0;
}
