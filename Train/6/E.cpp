#include<stdio.h>

int main()
{
	int n,x,y;
	int a[110];
	int t,i;
	scanf("%d",&t);
	while(t-->0){
		scanf("%d%d%d",&n,&x,&y);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(a[1]==x&&a[n]==y) printf("BOTH\n");
		if(a[1]==x&&a[n]!=y) printf("EASY\n");
		if(a[1]!=x&&a[n]==y) printf("HARD\n");
		if(a[1]!=x&&a[n]!=y) printf("OKAY\n");
	}
 return 0;
}
