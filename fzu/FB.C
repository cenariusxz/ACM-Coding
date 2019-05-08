#include<stdio.h>
#include<string.h>

int a[1005],b[1005];
bool v[1005];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,cnt=0,t;
		memset(v,0,sizeof(v));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(j=1;j<=n&&cnt<=a[i];j++){
				if(!v[j]){
					cnt++;
					t=j;
				}
			}
			cnt=0;
			b[i]=t;
		}
		for(i=1;i<=n;i++){
			printf("%d",b[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
