#include<stdio.h>
#include<string.h>

int a[15],s[15];

void init(){
	a[0]=s[0]=1;
	a[1]=s[1]=2;
	for(int i=2;i<=10;i++){
		a[i]=2*a[i-1];
		s[i]=s[i-1]+a[i];
	}
}

int main(){
	int n;
	init();
	scanf("%d",&n);
	int ans=0;
	int tmp=1e8,c=9;
	while(n>0){
		if(n/tmp){
			if(n/tmp==7){
				ans+=a[c-1];
				ans+=a[c-1];
				n=n-(n/tmp)*tmp;
				tmp/=10;
				c--;
			}
			else if(n/tmp==4){
				ans+=a[c-1];
				n=n-(n/tmp)*tmp;
				tmp/=10;
				c--;
				
			}
		}
		else{
			tmp/=10;
			c--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
