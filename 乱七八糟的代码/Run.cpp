#include<stdio.h>
#include<string.h>
using namespace std;

const int maxn=1e5+5;

int num[maxn];
int sum[maxn];
int l[maxn],r[maxn];


int main(){
	memset(sum,0,sizeof(sum));
	memset(num,0,sizeof(num));
	int n,t,k;
	scanf("%d%d%d",&n,&t,&k);
	for(int i=1;i<=t;++i)scanf("%d",&num[i]);
	num[0]=1;
	sum[0]=1;
	l[0]=1;r[0]=1;
	for(int i=1;i<=t;++i){
		sum[i]=sum[i-1]+num[i];
		l[i]=r[i-1]+1;
		r[i]=sum[i];
	}
	int tmp=0;
	for(int i=1;i<=t;++i){
		if(num[i+1]<num[i]){
			tmp+=num[i]-num[i+1];
		}
	}
	if(tmp>k)printf("-1\n");
	else{
		for(int i=t;i>=1;--i){
			int ss;
			if(num[i]>num[i-1])ss=num[i-1]-1;
			else ss=num[i]-1;
			if(!ss){
				for(int j=l[i];j<=r[i];++j){
					printf("%d %d\n",j,l[i-1]);
				}
			}
			else if(k-tmp>=ss){
				for(int j=l[i];j<=r[i];++j){
					printf("%d %d\n",l[i-1],j);
				}
				tmp+=ss;
			}
			else{
				int q=ss-(k-tmp)+1;
				for(int j=1;j<=q;++j){
					printf("%d %d\n",l[i-1]+j-1,l[i]+j-1);
				}
				for(int j=q+1;j<=num[i];++j){
					printf("%d %d\n",l[i-1],l[i]+j-1);
				}
				tmp=k;
			}
		}
	}
	return 0;
}
