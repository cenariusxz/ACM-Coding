#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
//	freopen("stdin.txt","w",stdout);
	srand((unsigned)time(NULL));
	int i;
	for(i=3;i<=53;i++)
		printf("%d\n",i);
	for(i=1;i<=149;i++){
		printf("%d\n",rand()%(1000000000-60)+60);
	}
	printf("1000000000\n");
	return 0;
}
