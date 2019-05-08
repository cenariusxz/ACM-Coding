#include<stdio.h>
#include<string.h>

int a[1000005],s[1000005];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,sum=0;
		char c=getchar();
		while(c>'9'||c<'0')c=getchar();
		for(i=1;i<=n;i++){
			a[i]=c-'0';
			sum+=a[i];
			c=getchar();
		}
		memset(s,0,sizeof(s));
		int ans=0;
		for(i=1;i<=n;i++){
			int tmp=(10-a[i])%10-a[i];
			if(s[i-1]>0)s[i]=tmp+s[i-1];
			else s[i]=tmp;
			if(s[i]>ans)ans=s[i];
		}
		printf("%d\n",sum+ans);
	}
	return 0;
}
