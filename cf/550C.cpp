#include<stdio.h>
#include<string.h>

char s[105];
bool f[1000];

int main(){
	scanf("%s",s+1);
	int l=strlen(s+1);
	int i,j;
	memset(f,0,sizeof(f));
	for(i=1;i<=l;i++){
		if(s[i]=='0'){
			printf("YES\n0\n");
			return 0;
		}
		if(s[i]=='8'){
			printf("YES\n8\n");
			return 0;
		}
	}
	if(f){
		for(i=l;i>=1;i--){
			if(s[i]=='1'){
				if(f[6]){
					printf("YES\n16\n");
					return 0;
				}
				if(f[12]){
					printf("YES\n112\n");
					return 0;
				}
				if(f[52]){
					printf("YES\n152\n");
					return 0;
				}
				if(f[92]){
					printf("YES\n192\n");
					return 0;
				}
				if(f[36]){
					printf("YES\n136\n");
					return 0;
				}
				if(f[76]){
					printf("YES\n176\n");
					return 0;
				}
				if(f[44]){
					printf("YES\n144\n");
					return 0;
				}
				if(f[2])f[12]=1;
				f[1]=1;
			}
			if(s[i]=='2'){
				if(f[4]){
					printf("YES\n24\n");
					return 0;
				}
				f[2]=1;
			}
			if(s[i]=='3'){
				if(f[2]){
					printf("YES\n32\n");
					return 0;
				}
				if(f[12]){
					printf("YES\n312\n");
					return 0;
				}
				if(f[52]){
					printf("YES\n352\n");
					return 0;
				}
				if(f[92]){
					printf("YES\n392\n");
					return 0;
				}
				if(f[44]){
					printf("YES\n344\n");
					return 0;
				}
				if(f[36]){
					printf("YES\n336\n");
					return 0;
				}
				if(f[76]){
					printf("YES\n376\n");
					return 0;
				}
				if(f[6])f[36]=1;
				f[3]=1;
			}
			if(s[i]=='4'){
				if(f[4])f[44]=1;
				f[4]=1;
			}
			if(s[i]=='5'){
				if(f[12]){
					printf("YES\n512\n");
					return 0;
				}
				if(f[52]){
					printf("YES\n552\n");
					return 0;
				}
				if(f[92]){
					printf("YES\n592\n");
					return 0;
				}
				if(f[44]){
					printf("YES\n544\n");
					return 0;
				}
				if(f[36]){
					printf("YES\n536\n");
					return 0;
				}
				if(f[76]){
					printf("YES\n576\n");
					return 0;
				}
				if(f[6]){
					printf("YES\n56\n");
					return 0;
				}
				if(f[2])f[52]=1;
				f[5]=1;
			}
			if(s[i]=='6'){
				if(f[4]){
					printf("YES\n64\n");
					return 0;
				}
				f[6]=1;
			}
			if(s[i]=='7'){
				if(f[2]){
					printf("YES\n72\n");
					return 0;
				}
				if(f[12]){
					printf("YES\n712\n");
					return 0;
				}
				if(f[52]){
					printf("YES\n752\n");
					return 0;
				}
				if(f[92]){
					printf("YES\n792\n");
					return 0;
				}
				if(f[44]){
					printf("YES\n744\n");
					return 0;
				}
				if(f[36]){
					printf("YES\n736\n");
					return 0;
				}
				if(f[76]){
					printf("YES\n776\n");
					return 0;
				}
				if(f[6])f[76]=1;
				f[7]=1;
			}
			if(s[i]=='9'){
				if(f[12]){
					printf("YES\n912\n");
					return 0;
				}
				if(f[52]){
					printf("YES\n952\n");
					return 0;
				}
				if(f[92]){
					printf("YES\n992\n");
					return 0;
				}
				if(f[44]){
					printf("YES\n944\n");
					return 0;
				}
				if(f[36]){
					printf("YES\n936\n");
					return 0;
				}
				if(f[76]){
					printf("YES\n976\n");
					return 0;
				}
				if(f[6]){
					printf("YES\n96\n");
					return 0;
				}
				if(f[2])f[92]=1;
				f[9]=1;
			}
		}
	}
	printf("NO\n");
}
