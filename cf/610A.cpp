#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

int main(){
	int n;
	scanf("%d",&n);
	if(n%2)printf("0\n");
	else{
		int l=n/2;
		if(l%2)printf("%d\n",l/2);
		else printf("%d\n",l/2-1);
	}
	return 0;
}
