#include<stdio.h>
#include<string.h>
const int maxm=1e5+5;

char s[maxm],t[maxm];

int main(){
//	int T;
//	scanf("%d",&T);
//	while(T--){
		scanf("%s%s",s+1,t+1);
		int ls=strlen(s+1);
		int lt=strlen(t+1);
		if(ls>lt)printf("No\n");
		else if(ls==lt){
			if(strcmp(s+1,t+1)==0)printf("Yes\n");
			else printf("No\n");
		}
		else if(s[1]!=t[1])printf("No\n");
		else{
			int pos1=1,pos2=1;
			char c=s[1];
			bool f=1;
			while(pos1<=ls&&pos2<=lt){
				if(s[pos1]==t[pos2]){
					if(f&&t[pos2]!=c)f=0;
					pos1++;
					pos2++;
				}
				else{
					if(f){
						if(t[pos2]==c){
							break;
						}
						else{
							f=0;
							pos2++;
						}
					}
					else{
						pos2++;
					}
				}
			}
			if(pos1>ls){
				if(f){
					if(t[pos2]==c)printf("No\n");
					else printf("Yes\n");
				}
				else printf("Yes\n");
			}
			else printf("No\n");
		}
//	}
	return 0;
}
