#include<stdio.h>
#include<string.h>

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			int n;
			scanf("%d",&n);
			int i,num=0,sum=0;
			for(i=1;i<=n;i++){
				int a;
				scanf("%d",&a);
				sum^=a;
				if(a!=1)num++;
			}
			if((num==0&&sum==0)||(sum>0&&num>0))printf("John\n");
			else printf("Brother\n");
		}
	}
	return 0;
}
