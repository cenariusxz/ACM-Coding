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
	    for(int j=0;j<lena;j++)a[j] *= 2;       //��ÿһλ��2
	    for(int j=0;j<lena;j++){                    //�����е�ÿһλ��λ
            a[j+1] += a[j] / 10;
            a[j] %= 10;
	    }
        while(a[lena]){                                 //�ж��Ƿ���Ҫ����λ��
            a[lena+1] += a[lena] / 10;
            a[lena] %= 10;
            lena++;
        }
	}
	for(int i=lena-1;i>=0;i--) printf("%d",a[i]);
	printf("\n");
	return 0;
}


