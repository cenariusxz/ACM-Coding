#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int a[3][105];
int aa[3][105];
int b[105];
int num[105];

int main(){
	int n;
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	for(int i=1;i<=2;++i){
		for(int j=1;j<n;++j)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	aa[1][0]=aa[2][0]=0;
	for(int i=1;i<n;++i){
		aa[1][i]=aa[1][i-1]+a[1][i];
		aa[2][i]=aa[2][i-1]+a[2][i];
	}
	for(int i=1;i<=n;++i){
		num[i]=b[i]+aa[1][i-1]+aa[2][n-1]-aa[2][i-1];
	}
	sort(num+1,num+n+1);
	printf("%d\n",num[1]+num[2]);
	return 0;
}
