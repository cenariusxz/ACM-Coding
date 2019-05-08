#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b

char tmp1[105],tmp2[105],a[105][105];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			scanf("%s",a[i]);
		}
		for(i=2;i<=n;i++){
			int l1=strlen(a[i-1]),l2=strlen(a[i]);
			int l=min(l1,l2);
			for(int j=0;j<l;j++){
				if(a[i-1][j]==a[i][j])continue;
				else{
					for()
				}
			}
		}
	}
	return 0;
}
