#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int m1[105][105],m2[105][105];

int main(){
	for(int i=1;i<=100;++i){
		for(int j=1;j<=100;++j){
			if((i+j-1)%3)m1[i][j]=1;
			else m1[i][j]=0;
			if(( ( !(i%3) ) && (j%3) )||( (i%3) && ( !(j%3) ) )){
				m2[i][j]=0;
			}
			else m2[i][j]=1;
		}
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		int ans1=0,ans2=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				ans1+=m1[i][j];
				ans2+=m2[i][j];
			}
		}
		printf("%d\n",max(ans1,ans2));
	}
	return 0;
}
