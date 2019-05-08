#include<stdio.h>
#include<string.h>

const int maxn=1e6+5;
const int maxm=1e5+5;

char t[maxm];
int p[maxm];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",t);
		int i,j,ans=0;
		int m=strlen(t);
		p[0]=p[1]=0;
		for(i=1;i<m;i++){
			j=p[i];
			while(j&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:0;
		}
		if(p[m])printf("%d\n",(m-p[m]-m%(m-p[m]))%(m-p[m]));
		else printf("%d\n",m);
	}
	return 0;
}
