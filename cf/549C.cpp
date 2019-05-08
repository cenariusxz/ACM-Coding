#include<stdio.h>
#include<string.h>

int main(){
	int n,k,odd=0,even=0,i;
	bool f;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(a%2)odd++;
		else even++;
	}
	if(n==k){
		if(odd%2)printf("Stannis\n");
		else printf("Daenerys\n");
		return 0;
	}
	if((n-k)%2){
		f=0;
		if(odd<=(n-k)/2)f=1;
		if(k%2==0&&even<=(n-k)/2)f=1;
	}
	else{
		f=1;
		if(k%2&&even<=(n-k)/2)f=0;
	}
	if(f)printf("Daenerys\n");
	else printf("Stannis\n");
	return 0;
}
