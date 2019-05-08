#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100050;
vector<int> G[MAX_N];

int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) G[i].clear();
		for (int i = 0; i < n-1; i++) {
			int x;
			scanf("%d", &x);
			G[x].push_back(i+1);
			G[i+1].push_back(x);
		}

		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; i++) if (G[i].size() == 1) ++ans1;
		for (int i = 0; i < n; i++) if (G[i].size() &  1) ++ans2;
		printf("%d %d\n", (ans1>>1)+(ans1&1), (ans2>>1));
	}

	return 0;
}
