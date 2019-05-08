#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
#include<set>
#include<cstring>
#include<deque>
#include<bitset>
#include<list>
#include<time.h>
#include<queue>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<map>
#include<math.h>
using namespace std;
typedef long long LL;
#define IOS ios::sync_with_stdio(false)
#define FOR(i, l, r) for(int i = l; i <= r; ++i)
#define rands srand((unsigned)time(NULL))
#define lson rt << 1, l, mid
#define rson rt << 1| 1, mid + 1, r
#define cls(a, b)   memset(a, b,sizeof(a))
inline double Rand(double L, double R) { return L + (R - L) * rand() * 1.0; }
inline int maxa(int a, int b) { return a > b ? a : b; }
inline int mina(int a, int b) { return a < b ? a : b; }
inline double maxa(double a, double b) { return a > b ? a : b; }
inline double mina(double a, double b) { return a < b ? a : b; }
inline int qcmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }

double getdist(int x2, int y2, int x3, int y3) {
	return sqrt(1.0 * (x2 - x3) * (x2 - x3) + 1.0 * (y2 - y3) * (y2 - y3));
}

int main() {
	int T = 2;
	scanf("%d", &T);
	printf("%d\n",T);
	//getchar();
	while (T--) {
		int X[5],Y[5];
		for(int i = 1; i <= 4; ++i){
			printf("%d\n",i);
			scanf(" (%d,%d)",&X[i],&Y[i]);
			printf("%d %d\n",X[i],Y[i]);
		}
		//int s = abs(x2 * y3 + x3 * y4 + x4 * y2 - x2 * y4 - x3 * y2 - x4 * y3);
		double ab = getdist(X[2], Y[2], X[3], Y[3]);
		double bc = getdist(X[3], Y[3], X[4], Y[4]);
		double ac = getdist(X[2], Y[2], X[4], Y[4]);
		double C = ab + bc + ac;
		double x = (bc * X[2] + ac * X[3] + ab * X[4]) / C;
		double y = (bc * Y[2] + ac * Y[3] + ab * Y[4]) / C;
		double ans = getdist(x, y, X[1], Y[1]);
		printf("%.2f\n",ans);
	}
	return 0;
}
