#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;

int a[maxn];

int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%n){
		int ave=sum*1.0/n;
		int max1=0,max2=0;
		for(int i=1;i<=n;++i){
			if(a[i]<ave){
				max1+=ave-a[i];
			}
			if(a[i]>ave+1){
				max2+=a[i]-ave-1;
			}
		}
		printf("%d\n",max(max1,max2));
	}
	else{
		int ave=sum/n;
		int num=0;
		for(int i=1;i<=n;++i){
			if(a[i]>ave){
				num+=a[i]-ave;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
