#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;
	
const int maxn=1e6+5;
const int maxm=1e4+5;

int p[2005];    //自匹配数组

int kmp(char s[],char t[]){
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
			return 1;
		}
	}
	return 0;
}

char s[505][2005];
int S[505],top;

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]);
		}
		top=0;
		int ans=-1;
		S[++top]=n;
		for(int i=n-1;i>=1;--i){
			if(kmp(s[S[top]],s[i])){
				S[++top]=i;
			}
			else{
				if(S[top]>ans)ans=S[top];
				top--;
				if(!top){
					break;
				}
				i++;
			}
		}
		printf("Case #%d: %d\n",q,ans);
	}
	return 0;
}
