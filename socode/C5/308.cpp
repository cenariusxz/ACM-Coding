# include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	double sum = 0;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		sum += a;
	}
	printf("%.2lf\n", sum / n);
	return 0;
}
