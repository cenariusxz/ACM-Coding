#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100005];

int b[4];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i;
		memset(b,0,sizeof(b));
		bool f=1;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==25)b[1]++;
			else if(a[i]==50){
				b[2]++;
				if(b[1]){
					b[1]--;
				}
				else f=0;
			}
			else if(a[i]==100){
				b[3]++;
				if(b[1]&&b[2]){
					b[1]--;
					b[2]--;
				}
				else if(b[1]>=3)b[1]-=3;
				else f=0;
			}/*
			if(b[1]<=b[2]){
				b[1]-=b[2];
			}
			else{
				f=0;
			}
			if(f){
				if(b[2]>=b[1]){
					if(b[3]>b[1]){
						f=0;
					}
				}
				else if(b[2]<b[1]){
					if(b[3]>b[2]){
						b[3]-=b[2];
						b[2]-=b[2];
						b[1]-=b[2];
						if(b[3]>=3*b[1])f=0;
					}
				}
			}*/
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
