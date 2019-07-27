#include <bits/stdc++.h> 
using namespace std; 

int FBIotd(int n){
	if(n<=2)return 1;
	return FBIotd(n-1)+FBIotd(n-2);
} 

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",FBIotd(n));
	return 0;
}

