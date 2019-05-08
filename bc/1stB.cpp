#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

char s[105];
char t[15]=" anniversary";
int l=0;

bool check(int a,int b){
	int pos=1,p=1;
	int i,j;
	bool f1=0,f2=0,f3=0;
	for(i=1;i<=l;i++){
		if(!f1){
			if(s[i]==t[1]){
				int pos=1;
				bool f=1;
				for(pos=1;pos<=a&&f;pos++){
					if(s[i+pos-1]!=t[pos])f=0;
				}
				if(f){
					f1=1;
					i=i+pos-2;
				}
			}
		}
		else if(!f2){
			if(s[i]==t[a+1]){
				int pos=a+1;
				bool f=1;
				for(pos=a+1;pos<=b&&f;pos++){
					if(s[i+pos-a-1]!=t[pos])f=0;
				}
				if(f){
					f2=1;
					i=i+pos-a-2;
				}
			}
		}
		else if(!f3){
			if(s[i]==t[b+1]){
				int pos=b+1;
				bool f=1;
				for(pos=b+1;pos<=11&&f;pos++){
					if(s[i+pos-b-1]!=t[pos])f=0;
				}
				if(f)return 1;
			}
		}
	}
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		l=strlen(s+1);
		int i,j;
		bool f=1;
		for(i=1;i<10&&f;i++){
			for(j=i+1;j<=10&&f;j++){
				if(check(i,j)==1){
					f=0;
				}
			}
		}
		if(!f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
