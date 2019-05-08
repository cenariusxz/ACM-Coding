#include <stdio.h>
int main()
{
	int i,cnt=0;
	for(i=0;i<(1<<18);++i){
		if((i&(i>>6)&63)==(i&(i>>12)&63)) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
