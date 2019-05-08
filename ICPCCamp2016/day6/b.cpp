#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);

int n;

struct Point{
	double x,y,b;
	friend bool operator < (Point a,Point b){
		return a.y < b.y;
	}
}P[100010];

set<Point> st;

bool cmp(Point a,Point b){
	
	return a.b < b.b;
}

int Solve(double ang){
	printf("ang : %.2f\n",ang);
	double k = tan(ang);
	printf("k : %.2f\n",k);
	for(int i = 1; i <= n; ++i){
		P[i].b = P[i].y - k * P[i].x;
	}
	sort(P + 1,P + n + 1,cmp);
	st.clear();
	if(k > 0){
		for(int i = 1; i <= n; ++i){
			st.insert(P[i]);
		}
	}
	int res = 0;
	for(int i = 1; i <= n; ++i){
		printf("i %d\n",i);
		if(k < 0) st.insert(P[i]);
		auto it = st.find(P[i]);
		res += distance(it,st.end()) - 1;
		if(k>0) st.erase(it);
	}
	return res;
}

double Cal(int K){
	double L = 0,R = PI;
	while(fabs(L - R) > 1e-9){
		double mid = (L + R) / 2.0;
		if(Solve(mid) > K) L = mid;
		else R = mid;
	}
	return L;
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		int a,b;
		scanf("%d%d",&a,&b);
		P[i].x = a;
		P[i].y = b;
	}
	long long sum = n * (n - 1) / 2;
	if(n % 2){
		printf("%.12f\n",Cal(sum / 2 + 1));
	}
	else{
		double ans1 = Cal(sum / 2);
		double ans2 = Cal(sum / 2 + 1);
		printf("%.12f\n",(ans1 + ans2) / 2.0);
	}
	return 0;
}
