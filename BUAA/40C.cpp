#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;

int a[maxn],b[maxn];
int n,m;

bool check(int num,int f){
	if(num==n&&num==m){
		if(f){
			if(a[num]>b[num])return 1;
			else return 0;
		}
		else{
			if(a[num]<b[num])return 1;
			else return 0;
		}
	}
	if(num==n){
		if(f){
			if(a[num]>b[num])return 1;
			else return 0;
		}
		else{
			if(a[num]>b[num])return 0;
			else return 1;
		}
	}
	if(num==m){
		if(f){
			if(a[num]>b[num]||a[num]==b[num])return 1;
			else return 0;
		}
		else{
			if(a[num]<b[num])return 1;
			else return 0;
		}
	}
	if(f){
		if(a[num]>b[num])return 1;
		else if(a[num]<b[num])return 0;
		else return check(num+1,!f);
	}
	else{
		if(a[num]<b[num])return 1;
		else if(a[num]>b[num])return 0;
		else return check(num+1,!f);
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<=n;++i){
			scanf("%d",&a[i]);
		}
		scanf("%d",&m);
		for(int i=0;i<=m;++i){
			scanf("%d",&b[i]);
		}
		bool f=1;
		if(n==m){
			for(int i=0;i<=n&&f;++i){
				if(a[i]!=b[i])f=0;
			}
		}
		else f=0;
		if(f)printf("=\n");
		else{
			if(check(0,1))printf(">\n");
			else printf("<\n");
		}
	}
	return 0;
}
