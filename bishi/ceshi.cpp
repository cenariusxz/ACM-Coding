#include<stdio.h>

int a[55];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int p1=1,p2=n;
		int ans=0;
		while(p1<p2){
			if(a[p1]==a[p2]){p1++;p2--;}
			else if(a[p1]<a[p2]){
				p1++;
				a[p1]+=a[p1-1];
				ans++;
			}
			else{
				p2--;
				a[p2]+=a[p2+1];
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
