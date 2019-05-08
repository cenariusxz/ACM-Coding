#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

double x[1000];

int main(){
	int s;
	while(scanf("%d",&s)!=EOF){
		x[1]=1;
		x[2]=(x[1]+s/x[1])/2.0;
		int pos=2;
		int cnt=3;
		while(fabs(x[pos]-x[pos-1])>=1e-5){
			cnt++;
			pos++;
			x[pos]=(x[pos-1]+s/x[pos-1])/2.0;
		}
		printf("%d %.10lf\n",cnt,x[pos]);
	}
	return 0;
}
