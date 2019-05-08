#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int T,N,X,Y;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&N,&X,&Y);
		if(Y == 1){
			if(N < X){
				for(int i = 1; i <= N; ++i){
					printf("%d%c",i,i == N ? '\n' : ' ');
				}
			}
			else{
				for(int i = 1; i < X; ++i) printf("%d ",i);
				int ned = N - (X - 1);
				for(int i = X + 1; i <= X + ned; ++i){
					printf("%d%c",i,(i == X + ned) ? '\n' : ' ');
				}
			}
		}
		else{
			if(X <= N){
				for(int i = 1; i <= N; ++i){
					printf("%d%c",i,i == N ? '\n' : ' ');
				}
			}
			else{
				for(int i = 1; i < N; ++i) printf("%d ",i);
				printf("%d\n",X);
			}
		}
	}
	return 0;
}
