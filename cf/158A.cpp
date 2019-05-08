#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int a[55];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	int cnt=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>0)cnt++;
	}
	if(cnt<=k)printf("%d\n",cnt);
	else{
		cnt=k;
		sort(a+1,a+n+1,cmp);
		for(i=k+1;i<=n;i++){
			if(a[i]==a[k])cnt++;
			else break;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
