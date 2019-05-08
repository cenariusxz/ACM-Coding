#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

const int n=4;

char s[10][10];
char ans[10][10];
int cnt;
int px[20],py[20];
bool ff=0;

vector<int>v[20];

int check(int i,int j,int c){
	for(int k=1;k<=n;++k){
		if(ans[i][k]==c+'0')return 0;
		if(ans[k][j]==c+'0')return 0;
	}
	if(i<=2&&j<=2){
		if(s[1][1]==c+'0')return 0;
		if(s[1][2]==c+'0')return 0;
		if(s[2][1]==c+'0')return 0;
		if(s[2][2]==c+'0')return 0;
	}
	else if(i>2&&j<=2){
		if(s[3][1]==c+'0')return 0;
		if(s[3][2]==c+'0')return 0;
		if(s[4][1]==c+'0')return 0;
		if(s[4][2]==c+'0')return 0;
	}
	else if(i<=2&&j>2){
		if(s[1][3]==c+'0')return 0;
		if(s[1][4]==c+'0')return 0;
		if(s[2][3]==c+'0')return 0;
		if(s[2][4]==c+'0')return 0;
	}
	else if(i>2&&j>2){
		if(s[3][3]==c+'0')return 0;
		if(s[3][4]==c+'0')return 0;
		if(s[4][3]==c+'0')return 0;
		if(s[4][4]==c+'0')return 0;
	}

	return 1;
}

void dfs(int num){
	if(num==cnt+1){
		ff=1;
		return;
	}
	int a=px[num],b=py[num];
	for(int i=0;i<v[num].size();++i){
		if(check(a,b,v[num][i])){
			ans[a][b]=v[num][i]+'0';
			dfs(num+1);
			if(ff)return;
			ans[a][b]='*';
		}
	}
	if(ff)return;
}

int main(){
	int T,m=0;
	scanf("%d",&T);
	while(T--){
		ff=0;
		cnt=0;
		for(int i=1;i<=16;++i)v[i].clear();
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		memcpy(ans,s,sizeof(ans));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(s[i][j]=='*'){
					++cnt;
					px[cnt]=i;
					py[cnt]=j;
					int f[5]={0,0,0,0,0};
					for(int k=1;k<=n;++k){
						if(s[i][k]>='1'&&s[i][k]<='4')f[s[i][k]-'0']=1;
						if(s[k][j]>='1'&&s[k][j]<='4')f[s[k][j]-'0']=1;
					}
					if(i<=2&&j<=2){
						if(s[1][1]>='1'&&s[1][1]<='4')f[s[1][1]-'0']=1;
						if(s[1][2]>='1'&&s[1][2]<='4')f[s[1][2]-'0']=1;
						if(s[2][1]>='1'&&s[2][1]<='4')f[s[2][1]-'0']=1;
						if(s[2][2]>='1'&&s[2][2]<='4')f[s[2][2]-'0']=1;
					}
					else if(i>2&&j<=2){
						if(s[3][1]>='1'&&s[3][1]<='4')f[s[3][1]-'0']=1;
						if(s[3][2]>='1'&&s[3][2]<='4')f[s[3][2]-'0']=1;
						if(s[4][1]>='1'&&s[4][1]<='4')f[s[4][1]-'0']=1;
						if(s[4][2]>='1'&&s[4][2]<='4')f[s[4][2]-'0']=1;
					}
					else if(i<=2&&j>2){
						if(s[1][3]>='1'&&s[1][3]<='4')f[s[1][3]-'0']=1;
						if(s[1][4]>='1'&&s[1][4]<='4')f[s[1][4]-'0']=1;
						if(s[2][3]>='1'&&s[2][3]<='4')f[s[2][3]-'0']=1;
						if(s[2][4]>='1'&&s[2][4]<='4')f[s[2][4]-'0']=1;
					}
					else if(i>2&&j>2){
						if(s[3][3]>='1'&&s[3][3]<='4')f[s[3][3]-'0']=1;
						if(s[3][4]>='1'&&s[3][4]<='4')f[s[3][4]-'0']=1;
						if(s[4][3]>='1'&&s[4][3]<='4')f[s[4][3]-'0']=1;
						if(s[4][4]>='1'&&s[4][4]<='4')f[s[4][4]-'0']=1;
					}
					
					for(int k=1;k<=4;++k)if(!f[k])v[cnt].push_back(k);
				}
			}
		}
		if(cnt)dfs(1);
		printf("Case #%d:\n",++m);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				printf("%c",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
