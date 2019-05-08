#include<stdio.h>
#include<string.h>

char a[100005];

int main(){
	int i;
	scanf("%s",a+1);
	int pos=-1;
	int l=strlen(a+1);
	for(i=1;i<l;i++){
		if((a[i]-'0')%2)continue;
		if(a[i]<a[l]){
			pos=i;
			break;
		}
		else{
			pos=i;
		}
	}
	if(pos==-1)printf("-1\n");
	else{
		for(i=1;i<=l;i++){
			if(i==pos)printf("%c",a[l]);
			else if(i==l)printf("%c",a[pos]);
			else printf("%c",a[i]);
		}
		printf("\n");
	}
}
