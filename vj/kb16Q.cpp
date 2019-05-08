#include<stdio.h>
#include<string.h>

const int maxm=1e6+5;

char t[maxm];    //s为待匹配串，t为模板串
int p[maxm];    //自匹配数组
int ans[maxm];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int i,j;
		scanf("%s",t);
		int m=strlen(t);
		p[0]=p[1]=0;    //初始化自匹配数组
		for(i=1;i<m;i++){    //自匹配
			j=p[i];
			while(j&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:0;
		}
		int cnt=0;
		int tmp=m;
		for(;;){
			ans[++cnt]=m-p[tmp];
			if(p[tmp])tmp=p[tmp];
			else break;
		}
		printf("Case #%d: %d\n",q,cnt);
		for(int i=1;i<=cnt;++i){
			printf("%d",ans[i]);
			if(i==cnt)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
