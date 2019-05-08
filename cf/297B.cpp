#include<stdio.h>
#include<string.h>

char a[200000+5];
int b[100000+5];

int main(){
	int n;
	scanf("%s%d",a+1,&n);
	int i,l=strlen(a+1);
	memset(b,0,sizeof(b));
	int c;
	for(i=1;i<=n;i++){
		scanf("%d",&c);
		b[c]++;
	}
	int f=0;
	for(i=1;i<=l/2;i++){
		f+=b[i];
		if(f%2){
			char t=a[i];
			a[i]=a[l-i+1];
			a[l-i+1]=t;
		}
	}
	printf("%s\n",a+1);
	return 0;
}
