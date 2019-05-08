#include<stdio.h>
#include<string.h>

const int maxn=1e6+5;
const int maxm=1e6+5;

char t[maxm];
int p[maxm];

int main(){
	while(scanf("%s",t)!=EOF){
		int i,j,ans=0;
		int m=strlen(t);
		p[0]=p[1]=0;
		for(i=1;i<m;i++){
			j=p[i];
			while(j&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:0;
		}
		printf("%d\n",m-p[m]);
	}
	return 0;
}
