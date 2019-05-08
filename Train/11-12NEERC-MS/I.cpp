#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char S[10]={"0MDCLXVI"};
int main()
{
	int cnt[10]={0};
	string s;
	getline(cin,s);
	for(auto i:s){
		switch(i){
			case('I'):
			case('i'):cnt[7]++;break;
			case('V'):
			case('v'):cnt[6]++;break;
			case('X'):
			case('x'):cnt[5]++;break;
			case('L'):
			case('l'):cnt[4]++;break;
			case('C'):
			case('c'):cnt[3]++;break;
			case('D'):
			case('d'):cnt[2]++;break;
			case('M'):
			case('m'):cnt[1]++;break;
		}
	}
	for(int i=1;i<=min(cnt[1],3);i++) putchar('M');
	cnt[1]-=min(cnt[1],3);
	if((cnt[2]>0)+cnt[3]>=3){
		if(cnt[2]) putchar('D');
		for(int i=1;i<=min(cnt[3],3);i++) putchar('C');
		cnt[3]-=min(cnt[3],3);
	}
	else if(cnt[1]&&cnt[3]){
		printf("CM");
		cnt[1]--;
		cnt[3]--;
	}
	else{
		if(cnt[2]) putchar('D');
		for(int i=1;i<=min(cnt[3],3);i++) putchar('C');
		cnt[3]-=min(cnt[3],3);
	}
	if((cnt[4]>0)+cnt[5]>=3){
		if(cnt[4]) putchar('L');
		for(int i=1;i<=min(cnt[5],3);i++) putchar('X');
		cnt[5]-=min(cnt[5],3);
	}
	else if(cnt[3]&&cnt[5]){
		printf("XC");
		cnt[3]--;
		cnt[5]--;
	}
	else{
		if(cnt[4]) putchar('L');
		for(int i=1;i<=min(cnt[5],3);i++) putchar('X');
		cnt[5]-=min(cnt[5],3);
	}
	if((cnt[6]>0)+cnt[7]>=3){
		if(cnt[6]) putchar('V');
		for(int i=1;i<=min(cnt[7],3);i++) putchar('I');
		cnt[7]-=min(cnt[7],3);
	}
	else if(cnt[5]&&cnt[7]){
		printf("IX");
		cnt[5]--;
		cnt[7]--;
	}
	else{
		if(cnt[6]) putchar('V');
		for(int i=1;i<=min(cnt[7],3);i++) putchar('I');
		cnt[7]-=min(cnt[7],3);
	}
 return 0;
}
