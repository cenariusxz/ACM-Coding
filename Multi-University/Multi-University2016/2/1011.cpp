#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;

int a[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int sum=0;
		int k=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]&1){
				k++;
				sum+=a[i]-1;
			}
			else sum+=a[i];
		}
		if(k){
			int ans=sum/k;
			if(ans&1)ans--;
			printf("%d\n",ans+1);
		}
		else printf("%d\n",sum);
	}
	return 0;
}
