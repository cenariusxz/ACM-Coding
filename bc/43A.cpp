#include<stdio.h>
#include<string.h>

char s[105];


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int i;
		int l=strlen(s+1);
		for(i=1;i<=l;i+=2){
			printf("%c",s[i]);
		}
		printf("\n");
		for(i=l;i>=1;i-=2){
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
