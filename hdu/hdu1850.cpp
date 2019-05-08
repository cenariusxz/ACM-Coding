#include<stdio.h>
#include<string.h>

int a[105];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int i,s=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			s^=a[i];
		}
		int ans=0;
		for(i=1;i<=n;i++){
			if(a[i]>(s^a[i]))ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
