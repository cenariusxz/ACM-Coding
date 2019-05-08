#include <bits/stdc++.h>
using namespace std;

char s[15];

int main(){
	while(scanf("%s",s)!=EOF){
		int res = 1*(s[0]-'0') + 2*(s[2]-'0') + 3*(s[3]-'0') + 4*(s[4]-'0') + 5*(s[6]-'0') + 6*(s[7]-'0') + 7*(s[8]-'0') + 8*(s[9]-'0') + 9*(s[10]-'0');
		res %= 11;
		if((res == 10 && s[12] == 'X') || res == s[12]-'0')printf("Right\n");
		else{
			if(res == 10)s[12] = 'X';
			else s[12] = res + '0';
			printf("%s\n",s);
		}
	}
	return 0;
}
