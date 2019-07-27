#include <bits/stdc++.h>
using namespace std;

int main(){
	int yy,mm,dd;
	scanf("%d%d%d",&yy,&mm,&dd);
	if(mm >= 1 && mm <= 12){
		if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
			if(dd >= 1 && dd <= 31)printf("Yes\n");
			else printf("No\n");	
		}
		if(mm == 4 || mm == 6 || mm == 9 || mm == 11){
			if(dd >= 1 && dd <= 30)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 2){
			if( (yy % 400 == 0) || (yy % 4 == 0 && yy % 100 != 0) ){
				if(dd >= 1 && dd <= 29)printf("Yes\n");
				else printf("No\n");
			}
			else{
				if(dd >= 1 && dd <= 28)printf("Yes\n");
				else printf("No\n");	
			}
		}
	}
	else printf("No\n");
	return 0;	
}
