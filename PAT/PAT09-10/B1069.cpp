#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

char s[50];

int main(){
	int m,n,stx;
	scanf("%d%d%d",&m,&n,&stx);
	int cnt = 0;
	map<string,int>M;
	if(m < stx)printf("Keep going...\n");
	for(int i = 1 ; i <= m ; ++i){
		scanf("%s",s);
		string ss(s);
		if(i < stx)continue;
		if(i == stx){
			printf("%s\n",s);
			M[ss] = 1;
			cnt = 0;
		}
		else{
			cnt++;
			if(cnt == n){
				if(M[ss] == 0){
					printf("%s\n",s);
					M[ss] = 1;
					cnt = 0;
				}
				else cnt--;
			}
		}
	}
	return 0;
}
