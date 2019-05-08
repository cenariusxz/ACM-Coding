#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

char X[10][15]={
	"",
	"1001111",
	"0010010",
	"0000110",
	"1001100",
	"0100100",
	"0100000",
	"0001111",
	"0000000",
	"0000100"
};

int v[10];
int vis[10];
char s[10][15];
int n;

bool check(int a,int b){
	 for(int i=1;i<=9;++i){
		if(vis[i]){
//			printf("%d\n",i);
			if(s[i][a]!=X[i][b])return 0;
		}
	 }
	 return 1;
}

bool dfs(int x){
	if(x==7)return 1;
	bool f=0;
	for(int i=0;i<7;++i){
		if(!v[i]){
			if(check(x,i)){
//				printf("%d %d\n",x,i);
				v[i]=1;
				if(dfs(x+1)==1)return 1;
				v[i]=0;
			}
		}
	}
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i){
			int num;
			scanf("%d",&num);
			vis[num]=1;
			scanf("%s",s[num]);
		}
//		printf("%s\n%s\n",s[1],s[7]);
		memset(v,0,sizeof(v));
		if(dfs(0)==1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
