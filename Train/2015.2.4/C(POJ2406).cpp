#include<stdio.h>
#include<string.h>
int m,p[1000010];
char b[1000010];

 void KMP(){
 	int i,j=0;
 	p[1]=0;
 	for(i=2;i<=m;i++){
 		while(j>0&&b[j+1]!=b[i])
 			j=p[j];
 		if(b[j+1]==b[i]) j++;
 		p[i]=j;
 	}
 	for(i=m;i>=2;i--)
 		if(!p[i]&&m%i==0){
 			printf("%d\n",m/i);
 			break;
 		}
 	if(i==1){
 		for(i=2;i<=m;i++)
 			if(!p[i]){
 				printf("1\n");
 				break;
 			}
 		if(i>m) printf("%d\n",m);
 	}
 	for(i=1;i<=m;i++)
 		printf("%d ",p[i]);
 }

int main()
{
	int t,i;
	scanf("%d",&t);
	while(1){
		scanf("%s",b+1);
		if(b[1]=='.') break;
		m=strlen(b+1);
		KMP();
	}
 return 0;
}

