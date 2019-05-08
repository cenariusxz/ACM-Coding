#include <stdio.h>
#include <string.h>
using namespace std;

char s[25],t[10005];

int main(){
	int n;
	scanf("%s%d",s,&n);
	gets(t);
	while(1){
		gets(t);
		if(t[0] == '#' && t[1] == 0)return 0;
		if(strcmp(s,t) == 0){
			printf("Welcome in\n");
			return 0;
		}
		else{
			printf("Wrong password: %s\n",t);
			n--;
			if(n == 0){
				printf("Account locked\n");
				return 0;
			}
		}
	}
	return 0;
}
