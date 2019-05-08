#include<stdio.h>
#include<string.h>

char a[15]="CODEFORCES";
char b[105];

int main(){
	int i,j;
	scanf("%s",b);
	int l=strlen(b);
	bool f1=0;
	if(strcmp(b,a)==0)printf("YES\n");
	else if(l<=10)printf("NO\n");
	else{
		for(i=0;i<=10&&!f1;i++){
			bool f=1;
			int c=0;
			for(j=0;j<l&&f;j++){
				if(j>=i&&j<=i+l-11)continue;
				if(b[j]==a[c]){
					c++;
				}
				else f=0;
			}
			if(f)f1=1;
		}
		if(f1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
