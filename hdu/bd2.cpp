#include<stdio.h>
#include<string.h>

char s[100005],tmp[100005];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int k,i,j;
		int cnt=0;
		char c=getchar();
		while(c=='\n')c=getchar();
		while(c!='\n'){
			s[++cnt]=c;
			c=getchar();
		}
		scanf("%d",&k);
		int a=cnt/k;
		int b=cnt%k;
		for(i=1;i<=b;i++){
			for(j=1;j<=a+1;j++){
				tmp[i+(j-1)*k]=s[(i-1)*(a+1)+j];
			}
		}
		for(i=b+1;i<=k;i++){
			for(j=1;j<=a;j++){
				tmp[k*(j-1)+i]=s[b*(a+1)+(i-b-1)*a+j];
			}
		}
		printf("Case #%d:\n",q);
		for(i=1;i<=cnt;i++)printf("%c",tmp[i]);
		printf("\n");
	}
	return 0;
}
