#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

char s[300];

int main(){
	int T;
	scanf("%d",&T);
	for( int q = 1 ; q <= T ; ++ q){
		s[0] = '0';
		scanf("%s" ,s+1);
		int n = strlen(s+1);
		int pos = 0;
		for( int i = 1 ; i <= n ; ++ i ){
			if(s[i] < s[i-1]){
				pos = i;
				break;
			}
		}
		printf("Case #%d: ",q);
		if(pos==0){
			printf("%s\n",s+1);
			continue;
		}
//		printf("%d %c\n",pos,s[pos]);
		for(int i = pos ; i <= n ; ++ i ){
			s[i] = '9';
		}
		s[pos - 1] --;
		pos--;
		while(pos >= 1){
			if( s[pos] < s[pos-1] ){
				s[pos]='9';
				s[pos-1]--;
				pos--;
			}
			else break;
		}
		for(int i = 1 ; i <= n ; ++ i ){
			if(s[i] != '0'){
				printf("%s\n",s+i);
				break;
			}
		}
	}
	return 0;
}
