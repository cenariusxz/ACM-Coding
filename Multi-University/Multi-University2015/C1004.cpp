#include<stdio.h>
#include<string.h>

char s[51][51];
int ans,n,m;

void col1(int x,int y){
	ans++;
	for(int i=x,j=y;i>=1&&i<=n&&j>=1&&j<=m;i++,j--){
		if(s[i][j]=='B')s[i][j]='.';
		else if(s[i][j]=='G')s[i][j]='R';
		else break;
	}
}

void col2(int x,int y){
	ans++;
	for(int i=x,j=y;i>=1&&i<=n&&j>=1&&j<=m;i++,j++){
		if(s[i][j]=='R')s[i][j]='.';
		else if(s[i][j]=='G')s[i][j]='B';
		else break;
	}
}

int main(){
	int T,i,j;
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%s",s[i]+1);
		m=strlen(s[1]+1);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(s[i][j]=='R')col2(i,j);
				else if(s[i][j]=='B')col1(i,j);
				else if(s[i][j]=='G'){
					col2(i,j);
					col1(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
