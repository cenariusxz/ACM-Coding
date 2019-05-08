#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

int s[1005][1005];

//int xx[4]={1,-1,0,0};
//int yy[4]={0,0,1,-1};

//bool dfs(int x,int y){

//}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int num1=(n+m-1)%2;
		int num2=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int a;
				scanf("%d",&a);
				if(a)num2++;
			}
		}
		num2%=2;
		if(num1==num2)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
