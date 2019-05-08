#include<stdio.h>
#include<string.h>

int a[100005];

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[n]==1)printf("NO\n");
	else if(n==1&&a[n]==0)printf("YES\n0\n");
	else{
		if(a[n-1]==1){
			printf("YES\n");
			for(i=1;i<=n-1;i++)printf("%d->",a[i]);
			printf("%d\n",a[n]);
		}
		else{
			if(n==2)printf("NO\n");
			else if(a[n-2]==0){
				printf("YES\n");
				for(i=1;i<=n-3;i++)printf("%d->",a[i]);
				printf("(%d->%d)->%d\n",a[n-2],a[n-1],a[n]);
			}
			else printf("NO\n");
		}
	}
	return 0;
}
