#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[100005];

int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	ll sum=0;
	for(i=1;i<=n;i++){
		if(a[i]>=sum){
			ans++;
			sum+=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
