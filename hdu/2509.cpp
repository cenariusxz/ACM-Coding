#include<stdio.h>

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,sum=0,num=0;
		for(i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			if(a>1)num++;
			sum^=a;
		}
		if((num==0&&sum==0)||(sum>0&&num>0))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
