#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

char s[maxn];

int main(){
	int len = 0;
	while(scanf("%s",s+len)!=EOF){
		bool flag = 0;
		for(int i = len ; s[i] ; ++ i){
			if(s[i] == 'E'){
				s[i] = 0;
				flag = 1;
				break;
			}
			len++;
		}
		if(flag)break;
	}
	int t1 = 0, t2 = 0;
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == 'W')t1++;
		if(s[i] == 'L')t2++;
		if(max(t1,t2) >= 11 && abs(t1-t2) >= 2){
			printf("%d:%d\n",t1,t2);
			t1=0;t2=0;
		}
	}
	printf("%d:%d\n",t1,t2);
	printf("\n");
	t1=0;t2=0;
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == 'W')t1++;
		if(s[i] == 'L')t2++;
		if(max(t1,t2) >= 21 && abs(t1-t2) >= 2){
			printf("%d:%d\n",t1,t2);
			t1=0;t2=0;
		}
	}
	printf("%d:%d\n",t1,t2);
	return 0;
}
