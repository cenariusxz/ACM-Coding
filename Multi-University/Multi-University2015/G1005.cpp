#include<stdio.h>
#include<string.h>
typedef long long ll;

int c[10]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int main(){
	int n,t;
	int cnt=0;
	while(scanf("%d%d",&n,&t)!=EOF&&(n!=-1&&t!=-1)){
		int sum=0;
		ll p1=n%11;
		int tmp=n;
		while(tmp){
			sum+=tmp%10;
			tmp/=10;
		}
		int i,j,pos=1;;
		for(i=1;i<=t;i++){
			for(j=pos;j<=10;j++){
				if(sum>=c[j-1]&&sum<c[j]){
					pos=j;
					break;
				}
			}
			p1=(p1*(c[pos]%11)+sum%11)%11;
			int tmp=sum;
			while(tmp){
				sum+=tmp%10;
				tmp/=10;
			}
		}
		printf("Case #%d: ",++cnt);
		if(p1==0)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
