#include <bits/stdc++.h>
using namespace std;

int vis[15];

int main(){
	for(int i = 100 ; i * 3 < 1000 ; ++ i){
		memset(vis,0,sizeof(vis));
		int t1 = i, t2 = 2 * i, t3 = 3 * i;
		while(t1){
			vis[t1 % 10] ++ ;
			t1 /= 10;
		}
		while(t2){
			vis[t2 % 10] ++ ;
			t2 /= 10;
		}
		while(t3){
			vis[t3 % 10] ++ ;
			t3 /= 10;
		}
		bool flag = 1;
		for(int j = 1 ; j <= 9 ; ++ j){
			if(vis[j] != 1)flag = 0;
		}
		if(flag)printf("%d %d %d\n",i,i*2,i*3);
	}
	return 0;
}
