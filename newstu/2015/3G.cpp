#include<stdio.h>
#include<string.h>

char a[100][15]={
	{"0000000001"},
	{"0000000011"},
	{"0000000100"},
	{"0000000101"},
	{"0000000110"},
	{"0000000111"},
	{"0000001000"},
	{"0000001001"},
	{"0000001010"},
	{"0000001011"}
};

char b[100][15]={
	{"1000000000"},
	{"1100000000"},
	{"0001000000"},
	{"1001000001"},
	{"0011000100"},
	{"1101000000"},
	{"0001001000"},
	{"1000100010"},
	{"1000100000"},
	{"1001100000"}
};

int main(){
	char s[15];
	while(scanf("%s",s)!=EOF){
		for(int i=0;i<10;++i){
			if(strcmp(s,a[i])==0)printf("%s\n",b[i]);
		}
	}
	return 0;
}
