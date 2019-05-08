#include<stdio.h>
#include<string.h>

const int maxn=1e6+5;
inline int max(int a,int b){return a>b?a:b;}

int nxt[maxn],ext[maxn];
char s[maxn],t[maxn];

void EKMP(char s[],char t[],int lens,int lent){    //s为字母串，t为子串，并分别传入两串长度,ekmp是求t串与s串每个位置开头的最长公共前缀
	int i,j,p,l,k;
	nxt[0]=lent;j=0;    //t串自匹配，从t0开始的t的子串（即t串本身）与t串的最长公共前缀定为t串长度，j为已匹配完的位置，j+1即待匹配的位置
	while(j+1<lent&&t[j]==t[j+1])j++;    //先匹配t1开始的子串，若依次匹配直到失配
	nxt[1]=j;    //t1开始的子串与t串最长公共前缀长度即为j
	k=1;    //k为除t0外的最远匹配的开始字符，后续每次进行额外匹配就更新它
	for(i=2;i<lent;i++){    //i表示匹配从ti开始的子串与t串的最长公共前缀
		p=nxt[k]+k-1;    //p即为k所对应的最远失配位置，也是整个t串在自匹配过程中已经匹配到的位置
		l=nxt[i-k];
		if(i+l<p+1)nxt[i]=l;    //从ti开始已经确定匹配成功的结束位置与总匹配过的位置p比较，若结束位置小，则说明到i+l出已经失配，ti开始的最长公共前缀即为l，否则对超过p的部分进行匹配，直到失配并更新k
		else{
			j=max(0,p-i+1);
			while(i+j<lent&&t[i+j]==t[j])j++;
			nxt[i]=j;
			k=i;
		}
	}

	j=0;    //t与s的每个子串匹配，可以根据之前已经匹配过的s串的部分转化为t串与s中t的子串匹配，首先初始匹配位置赋为0
	while(j<lens&&j<lent&&s[j]==t[j])j++;    //先匹配s0开始的串和t串的最长公共前缀
	ext[0]=j;k=0;    //s0处的最长公共前缀即刚匹配完的j，将最长匹配到的位置对应的s0赋给k，之后进行与t串自匹配基本一样的操作，但是循环的从i=1开始，更新ext数组
	for(i=1;i<lens;i++){
		p=ext[k]+k-1;
		l=nxt[i-k];
		if(l+i<p+1)ext[i]=l;
		else{
			j=max(0,p-i+1);
			while(i+j<lens&&j<lent&&s[i+j]==t[j])j++;
			ext[i]=j;
			k=i;
		}
	}
}
