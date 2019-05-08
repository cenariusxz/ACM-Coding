#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int maxn=5e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;

int a[2][maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[0][i]);
	for(int i=0;i<=10;++i){
		int k=i&1;
		for(int j=1;j<=n;++j){
			if(j==1||j==n){
				a[k^1][j]=a[k][j];
			}
			else{
				int cnt=0;
				if(a[k][j-1])cnt++;
				if(a[k][j])cnt++;
				if(a[k][j+1])cnt++;
				if(cnt>=2)a[k^1][j]=1;
				else a[k^1][j]=0;
			}
			printf("%d ",a[k^1][j]);
		}
		printf("\n");
	}
	return 0;
}
