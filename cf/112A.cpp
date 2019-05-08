#include<stdio.h>
#include<string.h>

char a[105],b[105];

int main(){
	scanf("%s%s",a,b);
	int i;
	int l=strlen(a);
	for(i=0;i<l;i++){
		if(a[i]<'a')a[i]+='a'-'A';
		if(b[i]<'a')b[i]+='a'-'A';
	}
//	printf("%d\n",strcmp(a,b));
	if(strcmp(a,b)>0)printf("1\n");
	else if(strcmp(a,b)<0)printf("-1\n");
	else printf("0\n");
	return 0;
}
