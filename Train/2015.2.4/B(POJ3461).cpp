#include<stdio.h>
#include<string.h>
int m,n,p[10010];
char a[1000010],b[10010];

 void KMP(){
 	int i,j=0,cnt=0;
 	p[1]=0;
 	for(i=2;i<=m;i++){
 		while(j>0&&b[j+1]!=b[i])
 			j=p[j];
 		if(b[j+1]==b[i]) j++;
 		p[i]=j;
 	}
 	j=0;
 	for(i=1;i<=n;i++){
 		while(j>0&&b[j+1]!=a[i])
 			j=p[j];
 		if(b[j+1]==a[i]) j++;
 		if(j==m) cnt++;
 	}
 	printf("%d\n",cnt);
 }

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		scanf("%s",b+1);
		scanf("%s",a+1);
		m=strlen(b+1);
		n=strlen(a+1);
		KMP();
	}
 return 0;
}

