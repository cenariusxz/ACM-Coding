#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;

char s[110];
ll A;

int main(){
	while(scanf("%s",s + 1) != EOF){
		int len = strlen(s + 1);
		ll cur = s[1] - '0';
		for(int i = 3; i <= len; i += 2){
			if(s[i - 1] == '+'){
				cur += s[i] - '0';
			}
			else if(s[i - 1] == '*'){
				cur *= (s[i] - '0');
			}
		}
		vector<ll> v;
		v.push_back(s[1] - '0');
		for(int i = 3; i <= len; i += 2){
			if(s[i - 1] == '*'){
				int sz = v.size();
				v[sz - 1] *= 1ll * (s[i] - '0');
			}
			else{
				v.push_back(s[i] - '0');
			}
		}
		ll now = 0;
		for(int i = 0; i < v.size(); ++i){
			now += v[i];
		}
		scanf("%lld",&A);
		if(A == cur && A == now){
			printf("U\n");
		}
		else if(A == cur){
			printf("L\n");
		}
		else if(A == now){
			printf("M\n");
		}
		else{
			printf("I\n");
		}
	}
	return 0;
}
