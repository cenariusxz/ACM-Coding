#include<stdio.h>
#include<string.h>

int main(){
	int n,i;
	scanf("%d",&n);
	int a,b;
	int ans=0,tmp=0;
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		tmp-=a;
		tmp+=b;
		if(tmp>ans)ans=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
