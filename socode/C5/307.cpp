# include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	for(int i = n/3*3 ; i >= 1 ; i -= 3){
		printf("%d", i);
		if(i != 3)printf(" ");	
	}
	printf("\n");
	return 0;
}
