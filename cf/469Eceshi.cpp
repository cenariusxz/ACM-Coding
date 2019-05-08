#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int get(int a){
	int ans=0;
	while(a){
		ans+=a%10;
		a/=10;
	}
	return ans;
}

int sum[105];
int vis[100000000];

int main(){
	vis[0]=1;
	for(int i=1;i<=100;++i){
		sum[i]=sum[i-1]+get(i);
		sum[i]=1;
		printf("%d: %d\n",i,sum[i]);
	}
	return 0;
}
