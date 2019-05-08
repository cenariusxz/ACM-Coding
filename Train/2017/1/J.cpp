#include<stdio.h>
#include<string.h>

const int maxn=1e6+5;
const int maxm=1e4+5;

char s[maxn],t[maxm]={"cat"},t1[maxm]={"dog"};    //s为待匹配串，t为模板串
int p[maxm];    //自匹配数组

int main(){
	int T;
	scanf("%d",&T);
	while(T--){    //这个是字符串从下标0开始的
		scanf("%s",s);
		int i,j,ans=0;    //ans记录字符串出现次数
		int n=strlen(s),m=strlen(t);    //在题目中遇到过，其实strlen很慢，所以如果不先存起来可能有TLE的风险
		p[0]=p[1]=0;    //初始化自匹配数组
		for(i=1;i<m;i++){    //自匹配
			j=p[i];
			while(j&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:0;
		}
		j=0;            //注意 j=0
		for(i=0;i<n;i++){    //串匹配
			while(j&&s[i]!=t[j])j=p[j];
			if(s[i]==t[j])j++;
			if(j==m){
				ans++;        //此处记录出现次数（模板串在待匹配串中可重叠），或改为直接break表示是否出现过
			}
		}
		int res=ans;
		ans=0;
		i=0,j=0;
		n=strlen(s),m=strlen(t1);    //在题目中遇到过，其实strlen很慢，所以如果不先存起来可能有TLE的风险
		p[0]=p[1]=0;    //初始化自匹配数组
		for(i=1;i<m;i++){    //自匹配
			j=p[i];
			while(j&&t1[i]!=t1[j])j=p[j];
			p[i+1]=t1[i]==t1[j]?j+1:0;
		}
		j=0;            //注意 j=0
		for(i=0;i<n;i++){    //串匹配
			while(j&&s[i]!=t1[j])j=p[j];
			if(s[i]==t1[j])j++;
			if(j==m){
				ans++;        //此处记录出现次数（模板串在待匹配串中可重叠），或改为直接break表示是否出现过
			}
		}
		res+=ans;
		printf("%d\n",res);
	}
	return 0;
}

