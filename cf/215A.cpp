#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[100],b[100];

int main(){
	int n,m;
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++)scanf("%d",&b[i]);
	int cnt=0;
	int maxx=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!(b[j]%a[i])){
				if(b[j]/a[i]==maxx){
					cnt++;
				}
				else if(b[j]/a[i]>maxx){
					maxx=b[j]/a[i];
					cnt=1;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
