#include<stdio.h>
#include<string.h>

char s[105];

int main(){
	scanf("%s",s+1);
	int l=strlen(s+1);
	int i;
	for(i=2;i<=l;i++){
		if(s[i]>='a'){
			printf("%s\n",s+1);
			return 0;
		}
	}
	printf("%c",s[1]>='a'?s[1]-'a'+'A':s[1]-'A'+'a');
	for(i=2;i<=l;i++)printf("%c",s[i]-'A'+'a');
	printf("\n");
	return 0;
}
