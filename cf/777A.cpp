#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int M[6][3]={0,1,2,1,0,2,1,2,0,2,1,0,2,0,1,0,2,1};

int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	n%=6;
	printf("%d\n",M[n][x]);
	return 0;
}
