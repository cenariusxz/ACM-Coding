#include<stdio.h>
#include<string.h>

char s[1000005],t[10005];    //s为待匹配串，t为模板串
int p[10005];    //自匹配数组

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",t,s);
		int n=strlen(s);
		int m=strlen(t);
		int i,j,ans=0;
		p[0]=p[1]=0;
		for(i=1;i<m;i++){
			j=p[i];
			while(j&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:0;
		}
		j=0;
		for(i=0;i<n;i++){
			while(j&&s[i]!=t[j])j=p[j];
			if(s[i]==t[j])j++;
			if(j==m)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
