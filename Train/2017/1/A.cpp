#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if(x==1||y==1){
			printf("INF\n");
			continue;
		}
		if(x==2&&y==2&&(a>=2||b>=2)){
			printf("INF\n");
			continue;

		}
		int ans=0;
		while(a>=x||b>=y){
			int tmp=a/x;
			a%=x;
			a+=tmp;
			b+=tmp;
			ans+=tmp;

			tmp=b/y;
			b%=y;
			a+=tmp;
			b+=tmp;
			ans+=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
