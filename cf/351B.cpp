#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[3005];

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int sum=0;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(a[i]>a[j])sum++;
		}
	}
	int ans=0;
	if(sum%2){
		ans=sum*2-1;
	}
	else{
		ans=2*sum;
	}
	printf("%d\n",ans);
	return 0;
}
