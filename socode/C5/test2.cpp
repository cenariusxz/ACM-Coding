#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, d = INT_MAX+1;
	scanf("%d", &a);
	for (int c = 1; c <= a; c++)
	{
		scanf("%d", &b);
		if (b > d) d = b;
	}
	printf("%d\n", d);
	return 0;
}

