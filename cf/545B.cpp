#include<stdio.h>
#include<string.h>

char a[100005],b[100005];
char tmp[100005];

int main(){
	int i;
	scanf("%s%s",a+1,b+1);
	memset(tmp,0,sizeof(tmp));
	int n=strlen(a+1);
	int cnt=0;
	for(i=1;i<=n;i++){
		if(a[i]==b[i])tmp[i]='0';
		else{
			cnt++;
			if(cnt%2)tmp[i]=a[i];
			else tmp[i]=b[i];
		}
	}
	if(cnt%2)printf("impossible\n");
	else{
		for(i=1;i<=n;i++)printf("%c",tmp[i]);
		printf("\n");
	}
	return 0;
}
