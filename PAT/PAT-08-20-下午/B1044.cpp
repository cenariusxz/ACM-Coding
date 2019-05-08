#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

char low[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char high[13][5] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

char s[15];

int main(){
	int n;
	scanf("%d",&n);
	gets(s);
	while(n--){
		gets(s);
		int num = 0;
		if(s[0] >= '0' && s[0] <= '9'){
			for(int i = 0 ; s[i] ; ++i){
				num = num * 10 + s[i] - '0';
			}
			if(num <= 12)printf("%s\n", low[num]);
			else if(num%13)printf("%s %s\n", high[num/13], low[num%13]);
			else printf("%s\n",high[num/13]);
		}
		else{
			string t(s);
			int pos = t.find(' ');
			if(pos == -1){
				for(int i = 0 ; i < 13 ; ++i){
					if(t == string(low[i]))num += i;
					if(t == string(high[i]))num += i * 13;
				}
			}
			else{
				string h = t.substr(0,pos);
				string l = t.substr(pos+1);
				for(int i = 0 ; i < 13 ; ++i){
					if(l == string(low[i]))num += i;
					if(h == string(high[i]))num += i * 13;
				}
			}
			printf("%d\n",num);
		}
	}
	return 0;
}
