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
	if(b < 0){
		for(int i = 1 ; i <= -b ; ++i)a = '0' + a;
	}

	if(d == -1)printf("-");
	for(pos = 0 ; pos < a.length() ; ++pos){
		printf("%c",a[pos]);
		if(pos == 0 && a[pos] == '0')printf(".");
		if(pos == b && pos != a.length() - 1)printf(".");
	}
	for(pos; pos <= b; ++pos)printf("0");
	printf("\n");

	return 0;
}
