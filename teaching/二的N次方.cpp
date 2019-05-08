#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6 + 5;
int n;
int a[maxn],lena;
int main(){
	scanf("%d",&n);
	a[0]=1;
	lena=1;
	for(int i=1;i<=n;i++){
	    for(int j=0;j<lena;j++)a[j] *= 2;       //先每一位乘2
	    for(int j=0;j<lena;j++){                    //对已有的每一位进位
            a[j+1] += a[j] / 10;
            a[j] %= 10;
	    }
        while(a[lena]){                                 //判断是否需要增加位数
            a[lena+1] += a[lena] / 10;
            a[lena] %= 10;
            lena++;
        }
	}
	for(int i=lena-1;i>=0;i--) printf("%d",a[i]);
	printf("\n");
	return 0;
}


