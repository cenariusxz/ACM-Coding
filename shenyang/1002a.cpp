#include<stdio.h>
#include<string.h>

const int maxn=2005;
const int maxm=2005;

char t[505][maxm];    //s为待匹配串，t为模板串

int p[maxm];    //自匹配数组

int kmp(char s[],char t[]){
	int i,j;    //ans记录字符串出现次数
	int n=strlen(s),m=strlen(t);
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

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d%s",&n,t[1]);
		int cnt=1;
		int ans=-1;
		for(int i=2;i<=n;++i){
			scanf("%s",t[0]);
			for(int j=1;j<=cnt;++j){
				if(!kmp(t[0],t[j])){
					ans=i;
					break;
				}
			}
			if(ans==i)strcpy(t[++cnt],t[0]);
			else{
				strcpy(t[1],t[0]);
				cnt=1;
			}
		}
		printf("Case #%d: %d\n",q,ans);
	}
	return 0;
}
