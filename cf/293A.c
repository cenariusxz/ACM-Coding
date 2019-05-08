#include<stdio.h>
#include<string.h>

char s[105],t[105];

int main(){
	scanf("%s%s",s,t);
	bool f2=0;
	int f1=-1;
	int i,l=strlen(s);
	for(i=0;i<l;i++){
		if(~f1&&(s[i]!='z'||t[i]!='a')){
			if(s[i]!='z')s[i]++;
			else if(t[i]!='a'){
				s[i]=t[i]-1;
				s[f1]=t[f1];
			}
			f2=1;
			break;
		}
		if(s[i]<t[i]-1){
			s[i]++;
			f2=1;
			break;
		}
		else if(s[i]==t[i]-1){
			f1=i;
		}
	}
	if(f2)printf("%s\n",s);
	else printf("No such string\n");
	return 0;
}

