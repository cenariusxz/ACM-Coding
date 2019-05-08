#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

char ss[505][505];
int num1[505][505];
int num2[505][505];
int s[4][505][505];

int get(int a,int b){
	printf("%d %d %d %d\n",a,b,s[2][a][b-1],s[3][b][a-1]);
	return s[2][a][b-1]+s[3][b][a-1];
}

int get1(int a,int b,int c,int d){
	return s[2][c][d-1]-s[2][a-1][d-1]-s[2][c][b-1]+s[2][a-1][b-1];
}
int get2(int a,int b,int c,int d){
	return s[3][d][c-1]-s[3][b-1][c-1]-s[3][d][a-1]+s[3][b-1][a-1];
}

int main(){
	int h,w;
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;++i)scanf("%s",ss[i]+1);
	for(int i=1;i<=h;++i){
		for(int j=1;j<=w;++j){
			if(ss[i][j]=='.'&&ss[i][j+1]=='.')num1[i][j]++;
			if(ss[i][j]=='.'&&ss[i+1][j]=='.')num2[i][j]++;
		}
	}
	for(int i=1;i<=h;++i){
		for(int j=1;j<=w;++j){
			s[0][i][j]=s[0][i][j-1]+num1[i][j];
		}
	}
	for(int i=1;i<=w;++i){
		for(int j=1;j<=h;++j){
			s[1][i][j]=s[1][i][j-1]+num2[j][i];
		}
	}
	for(int i=1;i<=h;++i){
		for(int j=1;j<=w;++j){
			s[2][i][j]=s[2][i-1][j]+s[0][i][j];
		}
	}
	for(int i=1;i<=w;++i){
		for(int j=1;j<=h;++j){
			s[3][i][j]=s[3][i-1][j]+s[1][i][j];
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
//		printf("\n");
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);//		x1--;y1--;
		printf("%d\n",get1(x1,y1,x2,y2)+get2(x1,y1,x2,y2));
	}
	return 0;
}
