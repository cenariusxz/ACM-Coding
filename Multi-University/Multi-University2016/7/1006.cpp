#include<stdio.h>
#include<string.h>

const int maxn=1e6+5;
const int maxm=1e4+5;

char t[maxn];    //s为待匹配串，t为模板串
int p[maxm];    //自匹配数组

int main(){
	while(scanf("%s",t)!=EOF){    //这个是字符串从下标0开始的
		int i,j,ans=0;    //ans记录字符串出现次数
		int m=strlen(t);    //在题目中遇到过，其实strlen很慢，所以如果不先存起来可能有TLE的风险
		p[0]=p[1]=0;    //初始化自匹配数组
		for(i=1;i<m;i++){    //自匹配
			j=p[i];
			while(j&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:0;
		}
		for(i=1;i<=m;++i){
			printf("%d ",p[i]);
		}
		printf("\n");
	}
	return 0;
}
