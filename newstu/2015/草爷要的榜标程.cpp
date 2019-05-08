#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int num[105];

int main(){
	int n,k,i,j,xx,yy,t;
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(num,0,sizeof(num));
		for(i=1;i<=n;++i){
			for(j=1;j<=k;++j){
				scanf("%d:%d",&xx,&yy);
				num[i]+=xx*60+yy;
			}
			for(j=1;j<=k;++j){
				scanf("%d",&t);
				num[i]+=(t-1)*20;
			}
		}
		sort(num+1,num+n+1);//此处直接调用排序函数，也可以写课上讲的排序方法
		for(i=1;i<=n;++i){
			printf("%d",num[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
