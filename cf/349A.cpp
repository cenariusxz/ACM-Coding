#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int t;
		scanf("%d",&t);
		if(t == 25)a++;
		if(t == 50){
			if(a)a--,b++;
			else{
				printf("NO\n");
				return 0;
			}
		}
		if(t == 100){
			if(a && b)a--,b--,c++;
			else if(a >= 3)a-=3,c++;
			else{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}
