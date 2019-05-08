#include<stdio.h>
#include<string.h>
#include<math.h>

char s[10]={"abc"};
double p[10]={0.4,0.4,0.2};
double v1[10000],v2[10000];

char str[1000];

void init(){
	double sum=0;
	for(int i=0;s[i];++i){
		v1[s[i]]=sum;
		sum+=p[i];
		v2[s[i]]=sum;
	}
}

double code(char *str){
	double l=0,r=1;
	for(int i=0;str[i];++i){
		double len=r-l;
		r=l+len*v2[str[i]];
		l=l+len*v1[str[i]];
	}
	return (l+r)/2;
}

void decode(double num,int len){
	double tmp=num;
	for(int i=1;i<=len;++i){
		for(int j=0;s[j];++j){
			if(tmp>v1[s[j]]&&tmp<v2[s[j]]){
				printf("%c",s[j]);
				tmp=(tmp-v1[s[j]])/(v2[s[j]]-v1[s[j]]);
				break;
			}
		}
	}
	printf("\n");
}

int main(){
	init();
	printf("%d\n",strlen(str));
	printf("%lf\n",code(str));
	decode(code(str),strlen(str));
	return 0;
}
