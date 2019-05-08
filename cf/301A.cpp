#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[1005],b[1005];

int aabs(int a){
	return a>=0?a:-a;
}


int main(){
	int i;
	int n;
	scanf("%d",&n);
	int ans=0;
	scanf("%s%s",a,b);
	for(i=0;i<n;i++){
		ans+=min(min(aabs(a[i]-b[i]),aabs('9'-a[i]+b[i]-'0'+1)),'9'-b[i]+a[i]-'0'+1);
	}
	printf("%d\n",ans);

	return 0;
}
