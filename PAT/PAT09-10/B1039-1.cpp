#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 1e3 + 5;

char a[maxn],b[maxn];
int numa[maxn],numb[maxn],sum;

int main(){
	scanf("%s%s",a,b);
	for(int i = 0 ; a[i] ; ++i)numa[a[i]]++;
	for(int i = 0 ; b[i] ; ++i)numb[b[i]]++;
	for(int i = 0 ; i < 128 ; ++i)sum += min(numa[i],numb[i]);
	if(sum == strlen(b))printf("Yes %d\n",strlen(a) - sum);
	else printf("No %d\n",strlen(b) - sum);
	return 0;
}
