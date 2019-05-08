#include <stdio.h>
#include <string.h>

const int maxn = 1e4 + 5;

int Rank[maxn];

bool isPrime(int rk){
	for(int i = 2 ; i * i <= rk ; ++i){
		if(rk % i == 0)return false;
	}
	return true;
}

int main(){
	int n,m;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++i){
		int id;
		scanf("%d",&id);
		Rank[id] = i;
	}
	scanf("%d",&m);
	while(m--){
		int id;
		scanf("%d",&id);
		printf("%04d: ",id);
		if(Rank[id] == 0)printf("Are you kidding?\n");
		else if(Rank[id] == -1)printf("Checked\n");
		else{
			if(Rank[id] == 1)printf("Mystery Award\n");
			else if(isPrime(Rank[id]) == true)printf("Minion\n");
			else printf("Chocolate\n");
			Rank[id] = -1;
		}
	}
	return 0;
}
