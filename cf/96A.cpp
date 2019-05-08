#include<stdio.h>
#include<string.h>

char s[105];

int main(){
	int i;
	scanf("%s",s+1);
	int num=0;
	char f='2';
	for(i=1;i<=strlen(s+1);i++){
		if(s[i]==f){
			num++;
			if(num>=7){printf("YES\n");return 0;}
		}
		else{
			f=s[i];
			num=1;
		}
	}
	printf("NO\n");
	return 0;
}
