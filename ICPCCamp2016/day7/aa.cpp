#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;
const double eps = 1e-8;

int h,w;
double A[210][210];
double B[210][210];

int Gauss(){
	int i,col;
	for(i = 0,col = 0; col < w; ++i,++col){
		int r = i;
		for(int j = i + 1; j < h; ++j){
			if(fabs(A[j][col]) > fabs(A[r][col])) r = j;
		}
		if(r != i){
			for(int j = col; j < w; ++j)
				swap(A[r][j],A[i][j]);
		}
		if(fabs(A[i][col]) < eps){
			--i;
			continue;
		}
		for(int j = w - 1; j >= col; --j) A[i][j] /= A[i][col];
		for(int k = 0; k < h; ++k) if(k != i){
			for(int j = w - 1; j >= col; --j){
				A[k][j] -= A[k][col] * A[i][j];
			}
		}
	}
	int res = 0;
	for(int i = 0; i < min(w,h); ++i){
		if(fabs(A[i][i]) > eps) res++;
	}
	return res;
}

int main(){
	scanf("%d%d",&h,&w);
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			scanf("%lf",&B[i][j]);
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			A[i][j] = B[i][j];
		}
	}
	int ans1 = Gauss();
	memset(A,0,sizeof(A));
	swap(w,h);
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			A[i][j] = B[j][i];
		}
	}
	int ans2 = Gauss();
	printf("%d\n",min(ans1,ans2));
	return 0;
}
