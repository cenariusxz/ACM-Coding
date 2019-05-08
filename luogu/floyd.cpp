#include <bits/stdc++.h>
using namespace std;

int M[maxn][maxn];

memset(M,0x3f,sizeof(g));

// 读入边并存储在M上

for(int k = 1 ; k <= n ; ++ k){
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			M[i][j] = min(M[i][j], M[i][k]+M[k][j]);
		}
	}
}
