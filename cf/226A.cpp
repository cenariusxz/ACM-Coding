#include<stdio.h>
#include<string.h>

char s[55];

int main(){
	int i;
	int n;
	scanf("%d",&n);
	char tmp='A';
	scanf("%s",s+1);
	int ans=0;
	for(i=1;i<=n;i++){
		if(s[i]!=tmp)ans++;
		tmp=s[i];
	}
	printf("%d\n",n-ans);
	return 0;
}
