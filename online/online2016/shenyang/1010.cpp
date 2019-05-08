#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll *primarr, *v;
ll q = 1, p = 1;

//π(n)
ll pi(ll n, ll primarr[], ll len)
{
	ll i = 0, mark = 0;
	for (i = len - 1; i > 0; i--) {
		if (primarr[i] < n) {
			mark = 1;
			break;
		}
	}
	if (mark)
		return i + 1;
	return 0;
}

//Φ(x,a)
ll phi(ll x, ll a, ll m)
{
	if (a == m)
		return (x / q) * p + v[x % q];
	if (x < primarr[a - 1])
		return 1;
	return phi(x, a - 1, m) - phi(x / primarr[a - 1], a - 1, m);
}

ll prime(ll n)
{
	char *mark;
	ll mark_len;
	ll count = 0;
	ll i, j, m = 7;
	ll sum = 0, s = 0;
	ll len, len2, len3;

	mark_len = (n < 10000) ? 10002 : ((ll)exp(2.0 / 3 * log(n)) + 1);

	//筛选n^(2/3)或n内的素数
	mark = (char *)malloc(sizeof(char) * mark_len);
	memset(mark, 0, sizeof(char) * mark_len);
	for (i = 2; i < (ll)sqrt(mark_len); i++) {
		if (mark[i])
			continue;
		for (j = i + i; j < mark_len; j += i)
			mark[j] = 1;
	}
	mark[0] = mark[1] = 1;

	//统计素数数目
	for (i = 0; i < mark_len; i++)
		if (!mark[i])
			count++;

	//保存素数
	primarr = (ll *)malloc(sizeof(ll) * count);
	j = 0;
	for (i = 0; i < mark_len; i++)
		if (!mark[i])
			primarr[j++] = i;

	if (n < 10000)
		return pi(n, primarr, count);

	//n^(1/3)内的素数数目
	len = pi((ll)exp(1.0 / 3 * log(n)), primarr, count);
	//n^(1/2)内的素数数目
	len2 = pi((ll)sqrt(n), primarr, count);
	//n^（2/3)内的素数数目
	len3 = pi(mark_len - 1, primarr, count);

	//乘积个数
	j = mark_len - 2;
	for (i = (ll)exp(1.0 / 3 * log(n)); i <= (ll)sqrt(n); i++) {
		if (!mark[i]) {
			while (i * j > n) {
				if (!mark[j])
					s++;
				j--;
			}
			sum += s;
		}
	}
	free(mark);
	sum = (len2 - len) * len3 - sum;
	sum += (len * (len - 1) - len2 * (len2 - 1)) / 2;

	//欧拉函数
	if (m > len)
		m = len;
	for (i = 0; i < m; i++) {
		q *= primarr[i];
		p *= primarr[i] - 1;
	}
	v = (ll *)malloc(sizeof(ll) * q);
	for (i = 0; i < q; i++)
		v[i] = i;
	for (i = 0; i < m; i++)
		for (j = q - 1; j >= 0; j--)
			v[j] -= v[j / primarr[i]];

	sum = phi(n, len, m) - sum + len - 1;
	free(primarr);
	free(v);
	return sum;
}

int main()
{
	ll n;
	ll count;
	int h;
	while(scanf("%lld", &n)!=EOF)
	{

		p=1;
		q=1;
		count = prime(n);
		printf("%lld\n",count);
	}
	return 0;
}
