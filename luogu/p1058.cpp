#include <bits/stdc++.h>
using namespace std;

char s[505][505];

int a[55][55],Max[55];
int m,n;

void printBlock(int l,int d){
	s[d-5][l+2] = s[d-5][l+6] = s[d-3][l] = s[d-3][l+4] = 
		s[d-2][l+6] = s[d][l] = s[d][l+4] = 43;
	s[d-5][l+3] = s[d-5][l+4] = s[d-5][l+5] =
		s[d-3][l+1] = s[d-3][l+2] = s[d-3][l+3] =
		s[d][l+1] = s[d][l+2] = s[d][l+3] = 45;
	s[d-4][l+1] = s[d-4][l+5] = s[d-1][l+5] = 47;
	s[d-4][l+6] = s[d-3][l+6] = s[d-2][l] = s[d-2][l+4] =
		s[d-1][l] = s[d-1][l+4] = 124;
	s[d-4][l+2] = s[d-4][l+3] = s[d-4][l+4] =
		s[d-3][l+5] = s[d-2][l+5] =
		s[d-2][l+1] = s[d-2][l+2] = s[d-2][l+3] =
		s[d-1][l+1] = s[d-1][l+2] = s[d-1][l+3] = ' ';
}

void print(int *a, int left,int right,int up,int down){
	int pdown = down,pleft = left;
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= a[i] ; ++ j){
			printBlock(pleft,pdown);
			pdown -= 3;
		}
		pdown = down;
		pleft += 4;
	}
}

int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		int K = 0, L = 1 + 4 * n + 2 * m;
		for(int i = 1 ; i <= m ; ++ i){
			for(int j = 1 ; j <= n ; ++ j){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i = 1 ; i <= m ; ++ i){
			Max[i] = 0;
			for(int j = 1 ; j <= n ; ++ j){
				Max[i] = max(Max[i],a[i][j]);
			}
			K = max(K, 3 + 2*(m-i) + 3*Max[i]);
		}
		for(int i = 1 ; i <= K ; ++ i){
			for(int j = 1 ; j <= L ; ++ j){
				s[i][j] = 46;
			}
			s[i][L+1] = 0;
		}
		for(int i = 1 ; i <= m ; ++ i){
			int up,down,left,right,lenk,lenl;
			down = K - 2 * (m-i);
			lenk = 3 + 2*(m-i) + 3*Max[i];
			up = down - lenk + 1;
			left = 1 + 2*(m-i);
			lenl = 3 + 4*n;
			right = left + lenl - 1;
			print(a[i],left,right,up,down);
		}
		for(int i = 1 ; i <= K ; ++ i){
			printf("%s\n",s[i]+1);
		}
	}
	return 0;
}
