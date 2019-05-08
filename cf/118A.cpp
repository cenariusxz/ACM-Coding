#include<stdio.h>
#include<string.h>

char s[105];

int main(){
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l;i++){
		if(s[i]!='a'&&s[i]!='A'
			&&s[i]!='o'&&s[i]!='O'
			&&s[i]!='y'&&s[i]!='Y'
			&&s[i]!='e'&&s[i]!='E'
			&&s[i]!='u'&&s[i]!='U'
			&&s[i]!='i'&&s[i]!='I'){
			printf(".%c",s[i]<'a'?s[i]-'A'+'a':s[i]);
		}
	}
	printf("\n");
	return 0;
}
