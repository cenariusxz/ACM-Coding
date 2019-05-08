#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[1005];

int main(){
	int n,b;
	scanf("%d%d",&n,&b);
	int i;
	int ans=0;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=b)ans++;
			else break;
		}
	}
	printf("%d\n",ans*2);
	return 0;
}
