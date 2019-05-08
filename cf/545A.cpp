#include<stdio.h>
#include<string.h>

int a[105][105],num[105];

int main(){
	int n,i,j;
	int cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		bool f=1;
		for(j=1;j<=n;j++){
			if(a[i][j]==1||a[i][j]==3)f=0;
		}
		if(f){
			num[++cnt]=i;

		}
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++){
		printf("%d",num[i]);
		if(i==cnt)printf("\n");
		else printf(" ");
	}
	return 0;
}
