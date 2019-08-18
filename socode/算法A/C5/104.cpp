#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
char s[maxn],t[maxn];
int a[maxn],lena,b[maxn],lenb;
int c[maxn],lenc;

void add(int a[], int lena, int b[], int lenb){
    lenc = max(lena, lenb);
    for(int i = 0 ; i < lenc ; ++ i){
        c[i] += a[i] + b[i];
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
//    if(c[lenc])lenc++;
    while(c[lenc]){
        c[lenc+1] += c[lenc] / 10;
        c[lenc] %= 10;
        lenc++;
    }
    while( !c[lenc-1] && lenc > 1 )lenc--;
}

void sub(int a[], int lena, int b[], int lenb){
    lenc = lena;
    for(int i = 0 ; i < lenc ; ++ i){
        c[i] += a[i] - b[i];
        if(c[i]<0){
            c[i+1]--;
            c[i] += 10;
        }
    }
    // 12387354673400000
    while( !c[lenc-1] && lenc > 1 )lenc--;
}

int mul(char s[], char t[]){
	// a [0 ~ lena-1]
	// b [0 ~ lenb-1]
	// c [0 ~ lena-1 + lenb-1] -> [0 ~ lena+lenb-2]
	// c lenc = lena+lenb-1 
	int lena = strlen(s);
	int lenb = strlen(t);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int lenc = lena+lenb-1;
	for(int i = 0 ; i < lena ; ++ i)a[lena-i-1] = s[i] - '0';
	for(int i = 0 ; i < lenb ; ++ i)b[lenb-i-1] = t[i] - '0';
	for(int i = 0 ; i < lena ; ++ i){
		for(int j = 0 ; j < lenb ; ++ j){
			c[i+j] += a[i] * b[j];
		}
	}
	for(int i = 0 ; i < lenc ; ++ i){
		c[i+1] += c[i]/10;
		c[i] %= 10;	
	}
	while(c[lenc]){
		c[lenc+1] += c[lenc]/10;
		c[lenc] %= 10;
		lenc++;	
	}
	while(!c[lenc-1] && lenc > 1)lenc--;
	return lenc;
}

int main(){
    scanf("%s%s",s,t);
    int lenc = mul(s,t);
    for(int i = lenc-1 ; i >= 0  ; -- i)printf("%d",c[i]);
    printf("\n");
    return 0;
}
