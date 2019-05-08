#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

inline int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int x[25],y[25];

inline int cal(int a,int b){
	return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,k,p,q,l;
		for(i=1;i<=n;i++){
			x[i]=read();
			y[i]=read();
		}
		int ans=0;
		for(i=1;i<=n-3;++i){
			for(j=i+1;j<=n-2;++j){
				for(k=j+1;k<=n-1;++k){
					for(p=k+1;p<=n;++p){
						int a[7];
						a[1]=cal(i,j);
						a[2]=cal(i,k);
						a[3]=cal(i,p);
						a[4]=cal(j,k);
						a[5]=cal(j,p);
						a[6]=cal(k,p);
						int minn=100000;
						int maxx=0;
						for(q=1;q<=6;q++){
							if(a[q]<minn)minn=a[q];
							if(a[q]>maxx)maxx=a[q];
						}
						int sum1=0,sum2=0;
						for(q=1;q<=6;q++){
							if(a[q]==minn)sum1++;
							if(a[q]==maxx)sum2++;
						}
						if(sum1==4&&sum2==2)ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
