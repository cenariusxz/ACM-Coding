#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	double a,b,s=0;
	char c[100];
	while(scanf("%s%lf%lf",c,&a,&b)!=EOF){
		s+=a*b;
	}
	printf("%.1lf\n",s+0.05);
	return 0;
}
