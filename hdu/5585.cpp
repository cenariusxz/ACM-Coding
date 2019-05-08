#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

char s[35];

int main(){
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		if(!((s[len-1]-'0')%2)||s[len-1]=='5'){
			printf("YES\n");
			continue;
		}
		int sum=0;
		for(int i=0;i<len;++i)sum+=s[i]-'0';
		if(!(sum%3)){
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}
