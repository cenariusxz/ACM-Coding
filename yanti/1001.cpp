#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

char a[1005],b[1005];
char ans[1005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%s%s",a,b);
		int la=strlen(a),lb=strlen(b);
		if(la<lb){
			for(int i=la-1;i>=0;--i){
				a[i+lb-la]=a[i];
			}
			for(int i=0;i<=lb-la-1;++i)a[i]='0';
		}
		else if(la>lb){
			for(int i=lb-1;i>=0;--i){
				b[i+la-lb]=b[i];
			}
			for(int i=0;i<=la-lb-1;++i)b[i]='0';
		}
		int c=0;
		for(int i=max(lb,la)-1;i>=0;--i){
			int tmp=a[i]-'0'+b[i]-'0'+c;
			if(tmp>9){
				tmp-=10;
				c=1;
			}
			else c=0;
			ans[i]=tmp+'0';
		}
		if(c==1)printf("1");
		printf("%s\n",ans);
	}
}
