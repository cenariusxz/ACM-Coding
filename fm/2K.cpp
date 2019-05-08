#include<stdio.h>
#include<string.h>

char s[35][35];
int l[26],r[26],u[26],d[26];
int ma[26][26],id[26],n,vis[26],v[26];
char ans[50];

void get(int i,int j,int k){
	if(s[i][j]!='A'+k){
		int c=s[i][j]-'A';
		if(!ma[k][c]){
			ma[k][c]=1;
			id[c]++;
		}
	}
}

void dfs(int ss,int t){
	ans[t]=ss+'A';
	v[ss]=1;
	if(t==n){
		for(int i=1;i<=n;++i)printf("%c",ans[i]);
		printf("\n");
		v[ss]=0;
		return;
	}
	int que[28],cnt=0;
	for(int i=0;i<26;++i){
		if(ma[ss][i])id[i]--;
		if(vis[i]&&!id[i]&&!v[i])que[++cnt]=i;
	}
	for(int i=1;i<=cnt;++i)dfs(que[i],t+1);
	for(int i=0;i<26;++i)if(ma[ss][i])id[i]++;
	v[ss]=0;
}

int main(){
	int h,w;
	while(scanf("%d%d",&h,&w)!=EOF){
		n=0;
		memset(ma,0,sizeof(ma));
		for(int i=0;i<26;++i){
			l[i]=u[i]=35;
			r[i]=d[i]=0;
			id[i]=vis[i]=v[i]=0;
		}
		for(int i=1;i<=h;++i)scanf("%s",s[i]+1);
		for(int i=1;i<=h;++i){
			for(int j=1;j<=w;++j){
				if(s[i][j]!='.'){
					int c=s[i][j]-'A';
					if(!vis[c]){
						vis[c]=1;
						n++;
					}
					if(i<u[c])u[c]=i;
					if(i>d[c])d[c]=i;
					if(j<l[c])l[c]=j;
					if(j>r[c])r[c]=j;
				}
			}
		}
		for(int k=0;k<26;++k){
			if(l[k]==35)continue;
			int i,j;
			i=u[k];
			for(j=l[k];j<=r[k];++j)get(i,j,k);
			i=d[k];
			for(j=l[k];j<=r[k];++j)get(i,j,k);
			j=l[k];
			for(i=u[k]+1;i<d[k];++i)get(i,j,k);
			j=r[k];
			for(i=u[k]+1;i<d[k];++i)get(i,j,k);
		}
		for(int i=0;i<26;++i){
			if(vis[i]&&!id[i])dfs(i,1);
		}
	}
	return 0;
}
