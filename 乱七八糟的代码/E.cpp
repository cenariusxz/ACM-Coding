#include <stdio.h>
#include <string.h>

int k;
int can[200010];
int a[20];
int L[100010],R[100010],cnt;

int main(){
	while(scanf("%d",&k) != EOF){
		for(int i = 1; i <= k; ++i){
			scanf("%d",&a[i]);
		}
		memset(can,0,sizeof(can));
		for(int i = -50000; i <= 50000; ++i){
			int v = i;
			for(int j = 1; j <= k; ++j){
				v = a[j] - v;
				if(v < 0) v = -v;
			}
			if(v <= 1){
				can[i + 50000] = 1;
			}
		}
		cnt = 0;
		int f = 0,l;
		for(int i = 0; i <= 100000; ++i){
			if(can[i] == 1){
				if(f == 0){
					f = 1;
					l = i - 50000;
				}
			}
			else{
				if(f){
					f = 0;
					L[++cnt] = l;
					R[cnt] = i - 1 - 50000;
				}
			}
		}
		if(f){
			f = 0;
			L[++cnt] = l;
			R[cnt] = 50000;
		}
		printf("%d\n",cnt);
		for(int i = 1; i <= cnt; ++i){
			printf("%d %d\n",L[i],R[i]);
		}
	}
	return 0;
}
