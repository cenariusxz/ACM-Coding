#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[10005];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=m;++i){
			int b;
			scanf("%d",&b);
			int l=b,r=n+1-b;
			if(l>r)swap(l,r);
			while(l<r){
				int t=a[l];
				a[l]=a[r];
				a[r]=t;
				l++;r--;
			}
		}
		for(int i=1;i<=n;++i){
			printf("%d",a[i]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
