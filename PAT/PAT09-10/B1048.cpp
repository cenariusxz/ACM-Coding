#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10005;

char s[maxn],t[maxn];

int main(){
	scanf("%s%s",s,t);
	string ss(s),tt(t);
	reverse(ss.begin(), ss.end());
	reverse(tt.begin(), tt.end());
	if(ss.length() < tt.length()){
		int add = tt.length() - ss.length();
		while(add--)ss += '0';
	}
	if(ss.length() > tt.length()){
		int add = ss.length() - tt.length();
		while(add--)tt += '0';
	}
	for(int i = 0 ; i < tt.length() ; ++i){
		if((i + 1) % 2){
			int tmp = (ss[i] - '0' + tt[i] - '0') % 13;
			if(tmp <= 9)tt[i] = '0' + tmp;
			else if(tmp == 10)tt[i] = 'J';
			else if(tmp == 11)tt[i] = 'Q';
			else tt[i] = 'K';
		}
		else{
			int tmp = tt[i] - ss[i];
			if(tmp < 0)tmp += 10;
			tt[i] = '0' + tmp;
		}
	}
	reverse(tt.begin(), tt.end());
	printf("%s\n",tt.c_str());
	
	return 0;
}
