#include<stdio.h>
#include<string.h>

char s[105];

int main(){
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l;i++){
		if(s[i]=='H'||s[i]=='Q'||s[i]=='9'){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
