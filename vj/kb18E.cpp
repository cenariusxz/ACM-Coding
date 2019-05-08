#include<stdio.h>
#include<string.h>

const int maxm=1e6+5;

char t[maxm];    //s为待匹配串，t为模板串
int p[maxm];    //自匹配数组

int main(){
	while(scanf("%s",t)!=EOF){    //这个是字符串从下标0开始的
		if(t[0]=='.')break;
		int i,j,ans=0;
		int m=strlen(t);
		p[0]=p[1]=0;    //初始化自匹配数组
		for(i=1;i<m;i++){    //自匹配
			j=p[i];
			while(j&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:0;
		}
		int l=m-p[m];
		if(m%l)printf("1\n");
		else printf("%d\n",m/l);
	}
	return 0;
}
