#include<stdio.h>
#include<string.h>

const int maxm=1e6+5;

char t[maxm];
int p[maxm];

int main(){
	int m;
	int cnt=0;
	while(scanf("%d",&m)!=EOF&&m){
		int i,j;
		scanf("%s",t);
		p[0]=p[1]=0;
		for(i=1;i<m;i++){
			j=p[i];
			while(j&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:0;
		}
		printf("Test case #%d\n",++cnt);
		for(int i=1;i<=m;++i){
			if(p[i]!=0&&!(p[i]%(i-p[i])))printf("%d %d\n",i,p[i]/(i-p[i])+1);
		}
		printf("\n");
	}
	return 0;
}
