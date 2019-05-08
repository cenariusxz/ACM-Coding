#include<stdio.h>
#include<string.h>

char a1[10][50]={"zero","one","two","three","four","five","six","seven","eight","nine"};
char a2[10][50]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char a3[10][50]={" "," ","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

int main(){
	int n;
//	scanf("%d",&n);
	for(n=0;n<=99;n++){
	if(n>=0&&n<=9)printf("%s",a1[n]);
	else if(n>=10&&n<=19)printf("%s",a2[n-10]);
	else if(!(n%10))printf("%s",a3[n/10]);
	else{
		printf("%s-%s",a3[n/10],a1[n%10]);
	}
	printf("\n");

	}
	return 0;
}
