#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	
	return 0;
}
