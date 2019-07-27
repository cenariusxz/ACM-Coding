#include <bits/stdc++.h>
using namespace std;

int main(){
	int yy,mm,dd;
	scanf("%d%d%d",&yy,&mm,&dd);
	if(mm < 1 || mm > 12)printf("No\n");
	else{
		if(mm == 1){
			if(dd >= 1 && dd <= 31)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 2){
			int days = 28;
			if( (yy % 400 == 0) || (yy % 100 != 0 && yy % 4 == 0) )days++;
			if(dd >= 1 && dd <= days)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 3){
			if(dd >= 1 && dd <= 31)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 4){
			if(dd >= 1 && dd <= 30)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 5){
			if(dd >= 1 && dd <= 31)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 6){
			if(dd >= 1 && dd <= 30)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 7){
			if(dd >= 1 && dd <= 31)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 8){
			if(dd >= 1 && dd <= 31)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 9){
			if(dd >= 1 && dd <= 30)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 10){
			if(dd >= 1 && dd <= 31)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 11){
			if(dd >= 1 && dd <= 30)printf("Yes\n");
			else printf("No\n");
		}
		if(mm == 12){
			if(dd >= 1 && dd <= 31)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;	
}
