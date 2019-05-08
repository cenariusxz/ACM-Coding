#include<stdio.h>
#include<string.h>

char s[105];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int l=strlen(s+1);
		if(l<=10)printf("%s\n",s+1);
		else printf("%c%d%c\n",s[1],l-2,s[l]);
	}
	return 0;
}
