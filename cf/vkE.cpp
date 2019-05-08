#include<stdio.h>
#include<string.h>

char a[100005],b[100005];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		scanf("%s%s",a,b);
		int i,j,c1=0,c2=0,k1,k2;
		int f=3;
		for(i=0;i+c1<=n&&i+c2<=n&&f;i++){
			if(a[i+c1]==b[i+c2])continue;
			if(f==2)f=0;
			if(f==0)break;
			if(a[i+c1]!=b[i+c2+1]&&a[i+c1+1]!=b[i+c2]&&f==3){
				c1++;
				c2++;
				if(a[i+c1]==b[i+c2])f=2;
				else f=0;
			}
			else if(a[i+c1]==b[i+c2+1]){
				k2=i+c2;
				c2++;
				if(c2>1)f=0;
			}
			else if(a[i+c1+1]==b[i+c2]){
				k1=i+c1;
				c1++;
				if(c1>1)f=0;
			}
			else f=0;
		}
		bool f1=1;
		if(!f)printf("0\n");
		else if(f==2)printf("2\n");
		else if(c1==1&&c2==1){
			if(k1<k2){
				for(i=k1+1;i<=k2;i++){
					if(i==k1+1){
						if(a[i]!=b[i-1]||b[i]!=a[i-1])f=0;
					}
					else if(a[i]!=a[i-2]||a[i]!=b[i-1]||b[i]!=b[i-2]||b[i]!=a[i-1])f=0;
				}
			}
			if(k2<k1){
				for(i=k2+1;i<=k1;i++){
					if(i==k2+1){
						if(a[i]!=b[i-1]||b[i]!=a[i-1])f=0;
					}
					else if(a[i]!=a[i-2]||a[i]!=b[i-1]||b[i]!=b[i-2]||b[i]!=a[i-1])f=0;
				}
			}
			if(f)printf("2\n");
			else if(a[k1]!=b[k2])printf("1\n");
			else printf("1\n");
		}
		else printf("0\n");
	}
	return 0;
}
