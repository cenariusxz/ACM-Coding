#include<stdio.h>
#include<string.h>

const int maxn=1e6+5;
const int maxm=1e4+5;

char s[maxn],t[maxm];
int p[maxm];

int main(){
	while(scanf("%s%s",s+1,t+1)!=EOF){   // 。。这个是从下标1开始的，恩修改的还是比较多的所以不是很建议
		int i,j,ans=0;
		int n=strlen(s+1),m=strlen(t+1);
		p[1]=p[2]=1;
		for(i=2;i<=m;i++){
			j=p[i];
			while(j>1&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:1;
		}
		j=1;
		for(i=1;i<=n;i++){
			while(j>1&&s[i]!=t[j])j=p[j];
			if(s[i]==t[j])j++;
			if(j==m+1){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
