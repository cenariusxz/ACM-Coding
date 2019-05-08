#include<stdio.h>
#include<string.h>

int main(){
	int v1,v2,t,d;
	scanf("%d%d%d%d",&v1,&v2,&t,&d);
	int i,ans=0;
	for(i=1;i<=t;i++){
		if(v1<v2){
			ans+=v1;
			v1+=d;
		}
		else{
			ans+=v2;
			v2+=d;
		}
	}
	printf("%d\n",ans);
}
