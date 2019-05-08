#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double PI=acos(-1);
const double eps=1e-5;

//4\8\12\16\20
//8\6\4\2\1

int sco[5]={8,6,4,2,1};
int len[6]={0,4,8,12,16,20};
double num[5];
double ans[25];
double res[25];

int main(){
//	double sum=PI*20*20;
	double sum=20;
	for(int i=0;i<5;++i){
//		num[i]=(PI*len[i+1]*len[i+1]-PI*len[i]*len[i])/sum;
		num[i]=(len[i+1]-len[i])/sum;
//		printf("%.5lf\n",num[i]);
	}
	memset(ans,0,sizeof(ans));
	memset(res,0,sizeof(res));
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			for(int k=0;k<5;++k){
				int s=sco[i]+sco[j]+sco[k];
				ans[s]+=num[i]*num[j]*num[k];
			}
		}
	}
	for(int i=1;i<25;++i)res[i]=res[i-1]+ans[i];
	for(int i=1;i<25;++i){
		if(ans[i]>eps){
			printf("%d %.6lf %.6lf\n",i,ans[i],res[i]);
		}
	}
	return 0;
}
