#include<stdio.h>
#include<string.h>

bool vis[5][15];
char s[5];

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			memset(vis,0,sizeof(vis));
			int i;
			for(i=1;i<=5;i++){
				scanf("%s",s);
				int t;
				if(strlen(s)==2){
					t=s[1]-'0';
				}
				else if(strlen(s)==3){
					t=10+(s[2]-'0');
				}
				if(s[0]=='A'){
					vis[1][t]=1;
				}
				if(s[0]=='B'){
					vis[2][t]=1;
				}
				if(s[0]=='C'){
					vis[3][t]=1;
				}
				if(s[0]=='D'){
					vis[4][t]=1;
				}
			}
			int j,k,ans=0;
			for(i=1;i<=4;i++){
				for(j=1;j<=9;j++){
					int tmp=0;
					for(k=0;k<=4;k++){
						if(vis[i][j+k])tmp++;
					}
					if(tmp>ans)ans=tmp;
				}
				int tmp=0;
				for(j=10;j<=13;j++){
					if(vis[i][j])tmp++;
				}
				if(vis[i][1])tmp++;
				if(tmp>ans)ans=tmp;
			}
			
			printf("%d\n",5-ans);
		}
	}
	return 0;
}
