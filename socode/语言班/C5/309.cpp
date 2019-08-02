# include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		if(i % 10 == 1){
			cnt ++;
			if(cnt != 1)printf(" ");
			printf("%d",a);	
		}
	}
	return 0;
}
