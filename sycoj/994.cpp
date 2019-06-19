#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int p1, p2, p3;
char s[maxn], t[maxn]; 

int main(){
	scanf("%d%d%d%s", &p1, &p2, &p3, s);
	for(int i = 0; s[i] ; ++ i){
		// if(s[i] == '-' && s[i-1] == '-')while(1){}
		if(s[i] == '-'){
			char left = s[i-1], right = s[i+1];
			int t1 = -1,t2 = -1;
			if(left >= '0' && left <= '9')t1=0;
			if(left >= 'a' && left <= 'z')t1=1;
			if(right >= '0' && right <= '9')t2=0;
			if(right >= 'a' && right <= 'z')t2=1;
			
			if(left >= right)putchar(s[i]);
			else if(left + 1 == right)continue;
			else if(t1 == t2 && t1 != -1){
				left++;right--;
				if(left >= 'a' && left <= 'z' && p1 == 2)left = left - 'a' + 'A', right = right - 'a' + 'A';
				int cnt = 0;
				for(char j = left ; j <= right ; ++ j){
					for(int k = 1 ; k <= p2 ; ++ k){
						if(p1 == 3)t[++cnt] = '*';
						else t[++cnt] = j;
					}
				}
				t[++cnt] = 0;
				if(p3 == 1)printf("%s",t+1);
				else{
					for(int j = cnt - 1 ; j >= 1 ; -- j)putchar(t[j]);
				}
			}
			else putchar(s[i]);
		}
		else putchar(s[i]);
	}
	return 0;
}


