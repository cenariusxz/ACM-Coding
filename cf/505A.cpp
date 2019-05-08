#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

char s[15],tmp[15];

int main(){
	scanf("%s",s+1);
	int l=strlen(s+1),i,j,k;
	for(i=1;i<=l+1;i++){
		for(j='a';j<='z';j++){
			int cnt=0;
			for(k=1;k<=l;k++){
				if(k==i){
					tmp[++cnt]=(char)j;
				}
				tmp[++cnt]=s[k];
			}
			if(i==l+1)tmp[++cnt]=(char)j;
			bool f=1;
			for(k=1;k<=cnt/2&&f;k++){
				if(tmp[k]!=tmp[cnt-k+1])f=0;
			}
			if(f){
				for(k=1;k<=cnt;k++)printf("%c",tmp[k]);
				printf("\n");
				return 0;
			}
		}
	}
	printf("NA\n");
	return 0;
}
