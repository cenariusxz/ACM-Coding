#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

char p1[105],p2[105];
char R[105] = {"Rock"};
char S[105] = {"Scissors"};
char P[105] = {"Paper"};

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s%s",p1,p2);
		if(strcmp(p1,p2) == 0){
			printf("Tie\n");
		}
		else if(strcmp(p1, R) == 0 && strcmp(p2, S) == 0){
			printf("Player1\n");
		}
		else if(strcmp(p1, S) == 0 && strcmp(p2, P) == 0){
			printf("Player1\n");
		}
		else if(strcmp(p1, P) == 0 && strcmp(p2, R) == 0){
			printf("Player1\n");
		}
		else{
			printf("Player2\n");
		}
	}
	return 0;
}

