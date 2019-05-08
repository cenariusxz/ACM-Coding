#include<stdio.h>
#include<string.h>

const int maxn=1e6+5;
const int maxm=1e4+5;

char s[maxn],t[5]="doge";
int p[5];

int main(){
	int m=strlen(t);
	int i,j,ans=0;
	p[0]=p[1]=0;    //初始化自匹配数组
	for(i=1;i<m;i++){    //自匹配
		j=p[i];
		while(j&&t[i]!=t[j])j=p[j];
		p[i+1]=t[i]==t[j]?j+1:0;
	}
	while(scanf("%s",s)!=EOF){
		int n=strlen(s);
		for(i=0;i<n;++i)if(s[i]>='A'&&s[i]<='Z')s[i]=s[i]-'A'+'a';
		j=0;            //注意 j=0
		for(i=0;i<n;i++){    //串匹配
			while(j&&s[i]!=t[j])j=p[j];
			if(s[i]==t[j])j++;
			if(j==m){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
