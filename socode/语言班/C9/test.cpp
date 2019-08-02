#include <bits/stdc++.h>
using namespace std;

int main(){
	int c,d;
	c=0;
	d=0;
	long long a,b;//b=0
	b=0;
	scanf("%lld",&a);
	if(a==0){
		printf("0");
	}
	else{
		while(a!=0){
			if(d=1){
				b=b+pow(10,c)*(a%2);
				a=a/2;
				++c;
				d=0;
		    }
		    else{
				b=b+a%2;
		        ++c;
			}
		}
	}
	printf("%lld\n",b); 
	return 0;
}

