#include<stdio.h>
#include<string.h>

int ma[26][26],id[26],vis[26],v[26],n;

char s[10],ans[50];

char read(){
	char c=getchar();
	while((c>'z'||c<'a')&&(c!='\n'))c=getchar();
	return c;
}

void dfs(int ss,int t){
	ans[t]=ss+'a';
	v[ss]=1;
	if(t==n){
		for(int i=1;i<=n;++i)printf("%c",ans[i]);
		printf("\n");
		v[ss]=0;
		return;
	}
	int que[50],cnt=0;
	for(int i=0;i<26;++i){
		if(ma[ss][i])id[i]--;
		if(vis[i]&&!id[i]&&!v[i])que[++cnt]=i;
	}
	for(int i=1;i<=cnt;++i)dfs(que[i],t+1);
	for(int i=0;i<26;++i)if(ma[ss][i])id[i]++;
	v[ss]=0;
}

int main(){
	int ccnt=0;
	while(scanf("%s",s)!=EOF){
		if(ccnt++)printf("\n");
		memset(ma,0,sizeof(ma));
		memset(id,0,sizeof(id));
		memset(vis,0,sizeof(vis));
		memset(v,0,sizeof(v));
		n=0;
		vis[s[0]-'a']=1;
		n++;
		char c1,c2;
		while(c1=getchar()){
			if(c1=='\n')break;
			if(c1>'z'||c1<'a')continue;
			int cc=c1-'a';
			if(!vis[cc]){
				vis[cc]=1;
				n++;
			}
		}
		bool f=1;
		while(f){
			c1=read();
			if(c1=='\n')break;
			c2=read();
			int cc1=c1-'a',cc2=c2-'a';
			if(!ma[cc1][cc2]){
				ma[cc1][cc2]=1;
				id[cc2]++;
			}
		}
		for(int i=0;i<26;++i)if(vis[i]&&!id[i])dfs(i,1);
	}
	return 0;
}
