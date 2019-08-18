#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,cnt=0;
	scanf("%d",&n);
	for(int i = 1 ; i*i <= n ; ++ i){
		if(n%i==0){
			if(i == n/i)cnt ++;
			else cnt += 2;
		}
	}
	printf("%d\n",cnt); 
	return 0;
}

