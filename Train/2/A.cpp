#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int num[105][105];
int n,m;
void print(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%2d ",num[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void re_r(int r){
	for(int i=1;i<=m/2;++i){
		swap(num[r][i],num[r][m-i+1]);
	}
}

void re_c(int c){
	for(int i=1;i<=n/2;++i){
		swap(num[i][c],num[n-i+1][c]);
	}
}

void reset(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			num[i][j]=++cnt;
		}
	}
}

int main(){
	while(scanf("%d%d",&m,&n)){
		reset();
		print();
		char s[10];
		while(scanf("%s",s)){
			if(s[0]=='E'||s[0]=='e')break;
			if(s[0]=='R'||s[0]=='r')re_r(s[1]-'0');
			if(s[0]=='C'||s[0]=='c')re_c(s[1]-'0');
			if(s[0]=='S'||s[0]=='s')reset();
			if(s[0]=='A'||s[0]=='a'){
				for(int i=1;i<=n;++i){
					for(int j=1;j<=m;++j)scanf("%d",&num[i][j]);
				}
			}
			print();
		}
	}
	return 0;
}
