#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

char a[10][1000][1000];

int main(){
	a[0][1][1]='+';
	a[1][1][1]='+';
	a[1][1][2]='+';
	a[1][2][1]='+';
	a[1][2][2]='*';
	for(int i=2;i<=9;++i){
		for(int k=1;k<=1<<i;++k)a[i][1][k]='+';
		for(int k=1;k<=1<<i;++k){
			if(k<=(1<<i)/2)a[i][2][k]='+';
			else a[i][2][k]='*';
		}
		for(int j=2;j<=1<<(i-1);++j){
			for(int k=1;k<=1<<i;++k){
				if(k<=(1<<i)/2)a[i][2*j-1][k]=a[i-1][j][k];
				else a[i][2*j-1][k]=a[i-1][j][k-(1<<(i-1))];
			}
			for(int k=1;k<=1<<i;++k){
				if(k<=(1<<i)/2)a[i][2*j][k]=a[i-1][j][k];
				else{
					if(a[i-1][j][k-(1<<i)/2]=='+')a[i][2*j][k]='*';
					else a[i][2*j][k]='+';
				}
			}
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=1<<n;++i){
		for(int j=1;j<=1<<n;++j){
			printf("%c",a[n][i][j]);
		}
		printf("\n");
	}
	return 0;
}
