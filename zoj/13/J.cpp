#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int ans=n;
		for(int i=1;i<=n;++i){
			int a;
			scanf("%d",&a);
			ans+=a;
		}
		printf("%d\n",ans);
	}
}
