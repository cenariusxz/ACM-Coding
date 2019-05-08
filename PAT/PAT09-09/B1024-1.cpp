#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

const int maxn = 1e4 + 5;

char s[maxn];

int getNum(char s[], int l, int r){
	int ans = 0, d = 1;
	if(s[l] == '-')d = -1, l++;
	if(s[l] == '+')d = 1, l++;
	for(int i = l ; i <= r ; ++i){
		ans = ans * 10 + s[i] - '0';
	}
	return d * ans;
}

int main(){
	scanf("%s",s);
	string a;
	int d,b,pos;
	if(s[0] == '-')d = -1;
	else d = 1;
	for(int i = 1 ; s[i] ; ++i){
		if(s[i] == 'E'){
			pos = i;
			break;
		}
		if(s[i] >= '0' && s[i] <= '9'){
			a += s[i];
		}
	}
	b = getNum(s, pos + 1, strlen(s) - 1);

	if(d == -1)printf("-");

	if(b < 0){
		for(int i = 1 ; i <= -b ; ++i)a = '0' + a;
		for(int i = 0 ; i < a.length() ; ++i){
			printf("%c",a[i]);
			if(i == 0)printf(".");
		}
	}
	else{
		if(a.length() < b + 1){
			int add = b + 1 - a.length();
			for(int i = 1 ; i <= add ; ++i)a += '0';
		}
		for(int i = 0 ; i < a.length() ; ++i){
			printf("%c",a[i]);
			if(a.length() > b + 1 && i == b)printf(".");
		}
	}
	printf("\n");

	return 0;
}
