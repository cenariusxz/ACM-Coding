#include<stdio.h>
#include<string.h>

int a[100005],b[100005];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int n,maxx=1000006,i;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int l=0,r=maxx;
		while(l<=r){
			int m=(l+r)/2;
			b[1]=a[1]-m;
			bool f=1;
			for(i=2;i<=n&&f;i++){
				if(a[i]-m<=b[i-1]+1&&a[i]+m>=b[i-1]+1){
					b[i]=b[i-1]+1;
				}
				else if(a[i]-m>b[i-1]+1){
					b[i]=a[i]-m;
				}
				else f=0;
			}
			if(f){
				r=m-1;
			/*	for(i=1;i<=n;i++){
					printf("%d ",b[i]);
				}
				printf("\n");*/
			}
			else l=m+1;
		}
		printf("Case #%d:\n%d\n",q,l);
	}
	return 0;
}
