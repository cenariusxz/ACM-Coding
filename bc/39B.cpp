#include<stdio.h>
#include<string.h>

int a[10005],m[10005];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,ans=0,ma=0;
		memset(m,0,sizeof(m));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>ma)ma=a[i];
			if(!m[a[i]])m[a[i]]=i;
		}
		for(i=1;i<=n;i++){
			int mm=0x3f3f3f3f;
			bool f=0;
			for(j=2*a[i];j<=ma;j+=a[i]){
				if(m[j]>i&&m[j]<mm){
					mm=m[j];
					f=1;
				}
			}
			if(f)ans+=mm;
		}
		printf("%d\n",ans);
	}
	return 0;
}
