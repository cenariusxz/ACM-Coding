#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	int ans=0;
	for(i=1;i<=n;i++){
		int tmp=0;
		for(j=1;j<=3;j++){
			int a;
			scanf("%d",&a);
			tmp+=a;
		}
		if(tmp>=2)ans++;
	}
	printf("%d\n",ans);
	return 0;
}
