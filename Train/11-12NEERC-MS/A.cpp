#include <stdio.h>
#include <math.h>

int m,n,k;
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int D[70],M[70],Y[70];

bool Leap(int y){
	if(y % 100 == 0) return y % 400 == 0;
	else return y % 4 == 0;
}

bool Cmp(int a1,int b1,int c1,int a2,int b2,int c2){
	if(c1 > c2) return true;
	else if(c1 < c2) return false;
	if(b1 > b2) return true;
	else if(b1 < b2) return false;
	if(a1 >= a2) return true;
	else return false;
}

int main(){
	scanf("%d%d%d",&m,&n,&k);
	int DD,MM,YY;
	scanf("%d.%d.%d",&DD,&MM,&YY);
	YY += 60;
	if(DD == 29 && MM == 2 && !Leap(YY)){
		DD = 1;
		MM = 3;
	}
	if(k > 0){
		D[1] = 1;
		M[1] = 1;
		Y[1] = 2012;
	}
	for(int i = 2; i <= k; ++i){
		D[i] = 1;
		M[i] = M[i - 1] + n;
		Y[i] = Y[i - 1];
		while(M[i] > 12){
			M[i] -= 12;
			Y[i]++;
		}
	}
	int aDD = DD;
	int aMM = MM;
	int aYY = YY;
	int ans = 0;
	for(int i = 1; i <= k; ++i){
		int tDD = DD;
		int tMM = MM;
		int tYY = YY;
		tMM += (i - 1) * m;
		while(tMM > 12){
			tMM -= 12;
			tYY++;
		}
		int top = month[tMM];
		if(Leap(tYY) && tMM == 2) top++;
		if(tDD > top){
			tDD = 1;
			tMM++;
		}
		while(tMM > 12){
			tMM -= 12;
			tYY++;
		}
		if(Cmp(tDD,tMM,tYY,D[i],M[i],Y[i])){
			ans = i;
		}
	}
	aMM += ans * m;
	while(aMM > 12){
		aMM -= 12;
		aYY++;
	}
	int top = month[aMM];
	if(Leap(aYY) && aMM == 2) top++;
	if(aDD > top){
		aDD = 1;
		aMM++;
	}
	while(aMM > 12){
		aMM -= 12;
		aYY++;
	}
	printf("%02d.%02d.%d\n",aDD,aMM,aYY);
	return 0;
}
