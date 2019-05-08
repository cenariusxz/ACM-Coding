#include<stdio.h>
#include<string.h>

char s[105],t[105];

int main(){
	scanf("%s%s",s,t);
	int n=strlen(s);
	for(int i=n-1;i>=0;i--){
		if(s[i]!='z'){
			s[i]++;
			for(int j=i+1;j<n;j++){
				s[j]='a';
			}
			break;
		}
	}
	if(!strcmp(s,t))printf("No such string\n");
	else printf("%s\n",s);
	return 0;
}
