#include<stdio.h>
#include<string.h>

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			int n,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			if(a>6000)ans++;
		}
		printf("%d\n",ans);
		}
	}
	return 0;
}
