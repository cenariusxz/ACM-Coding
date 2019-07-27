#include <bits/stdc++.h>
using namespace std;

int main(){
	int tmp = 1245;
		string num = "";
		while(tmp){
			num = (char)('0' + tmp%10) + num;
			tmp /= 10;	
		}
		cout << num << endl;
	return 0;	
}
