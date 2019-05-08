#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

char a[50],b[50];

int main(){
	while(scanf("%s%s",a,b)!=EOF){
		int pos1=0,pos2=0;
		int ma1=0,mi1=0,pa1=0,ma2=0,mi2=0,pa2=0;
		
		if(strcmp(a,b)==0){
			printf("I'm angry!\n");
			continue;
		}

		while(a[pos1]&&a[pos1]>='0'&&a[pos1]<='9'){
			ma1=ma1*10+a[pos1]-'0';
			pos1++;
		}
		while(b[pos2]&&b[pos2]>='0'&&b[pos2]<='9'){
			ma2=ma2*10+b[pos2]-'0';
			pos2++;
		}
		if(ma1<ma2){
			printf("Wow! Such feature! Very smart! I'm excited!\n");
			continue;
		}
		else if(ma1>ma2){
			printf("I'm angry!\n");
			continue;
		}

		while(a[pos1]>'9'||a[pos1]<'0')pos1++;
		while(b[pos2]>'9'||b[pos2]<'0')pos2++;
		while(a[pos1]&&a[pos1]>='0'&&a[pos1]<='9'){
			mi1=mi1*10+a[pos1]-'0';
			pos1++;
		}
		while(b[pos2]&&b[pos2]>='0'&&b[pos2]<='9'){
			mi2=mi2*10+b[pos2]-'0';
			pos2++;
		}
		if(mi1<mi2){
			printf("Wow! Such feature! Very smart! I'm excited!\n");
			continue;
		}
		else if(mi1>mi2){
			printf("I'm angry!\n");
			continue;
		}

		while(a[pos1]>'9'||a[pos1]<'0')pos1++;
		while(b[pos2]>'9'||b[pos2]<'0')pos2++;
		while(a[pos1]&&a[pos1]>='0'&&a[pos1]<='9'){
			pa1=pa1*10+a[pos1]-'0';
			pos1++;
		}
		while(b[pos2]&&b[pos2]>='0'&&b[pos2]<='9'){
			pa2=pa2*10+b[pos2]-'0';
			pos2++;
		}
		if(pa1<pa2){
			printf("Wow! Such feature! Very smart! I'm excited!\n");
			continue;
		}
		else if(pa1>pa2){
			printf("I'm angry!\n");
			continue;
		}

		if(a[pos1]==0){
			printf("I'm angry!\n");
			continue;
		}
		else if(b[pos2]==0){
			printf("Wow! Such feature! Very smart! I'm excited!\n");
			continue;
		}

		while(a[pos1]==b[pos2]){
			pos1++;
			pos2++;
		}
		if(a[pos1]==0){
			printf("Wow! Such feature! Very smart! I'm excited!\n");
			continue;
		}
		else if(b[pos2]==0){
			printf("I'm angry!\n");
			continue;
		}

		if(a[pos1]>='0'&&a[pos1]<='9'){
			if(b[pos2]>='0'&&b[pos2]<='9'){
				pa1=0;
				pa2=0;
				while(a[pos1]&&a[pos1]>='0'&&a[pos1]<='9'){
					pa1=pa1*10+a[pos1]-'0';
					pos1++;
				}
				while(b[pos2]&&b[pos2]>='0'&&b[pos2]<='9'){
					pa2=pa2*10+b[pos2]-'0';
					pos2++;
				}
				if(pa1<pa2){
					printf("Wow! Such feature! Very smart! I'm excited!\n");
					continue;
				}
				else if(pa1>pa2){
					printf("I'm angry!\n");
					continue;
				}
			}
			else{
					printf("Wow! Such feature! Very smart! I'm excited!\n");
					continue;
			}
		}
		else{
			if(b[pos2]>='0'&&b[pos2]<='9'){
				printf("I'm angry!\n");
				continue;
			}
			else{
				if(a[pos1]<b[pos2]){
					printf("Wow! Such feature! Very smart! I'm excited!\n");
					continue;
				}
				else{
					printf("I'm angry!\n");
					continue;
				}
			}
		}

	}
	return 0;
}
