#include<stdio.h>
#include<string.h>

char s[205];

int main(){
	scanf("%s",s+1);
	int l=strlen(s+1),i;
	for(i=1;i<=l;i++){
		if(s[i]=='.')printf("0");
		else if(s[i]=='-'){
			i++;
			if(s[i]=='.')printf("1");
			else if(s[i]=='-')printf("2");
		}
	}
	printf("\n");
	return 0;
}
