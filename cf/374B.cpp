#include<stdio.h>
#include<string.h>
typedef long long ll;

char a[100005];

int main(){
	scanf("%s",a+1);
	int l=strlen(a+1);
	int i,j;
	ll ans=1;
	for(i=1;i<l;i++){
		int tmp=1;
		if((a[i]-'0'+a[i+1]-'0')!=9)continue;
		while(i<l&&a[i]-'0'+a[i+1]-'0'==9){
			tmp++;
			i++;
		}
		if(tmp%2){
			ans*=(tmp/2+1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
