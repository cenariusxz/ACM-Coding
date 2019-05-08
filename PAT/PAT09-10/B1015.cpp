#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;

struct people {
  int id, a, b;
  bool operator < (const people x)const {
    if (a + b == x.a + x.b&&a == x.a)return id < x.id;
    if (a + b == x.a + x.b)return a > x.a;
    return a + b > x.a + x.b;
  }
}lv1[maxn],lv2[maxn],lv3[maxn],lv4[maxn];

int cnt1, cnt2, cnt3, cnt4;

int main() {
  int n, l, h;
  scanf("%d%d%d", &n, &l, &h);
  for (int i = 1; i <= n; ++i) {
    people tmp;
    scanf("%d%d%d", &tmp.id, &tmp.a, &tmp.b);
    if (tmp.a >= h&&tmp.b >= h)lv1[++cnt1] = tmp;
    else if (tmp.a >= h&&tmp.b >= l)lv2[++cnt2] = tmp;
    else if (tmp.a >= l&&tmp.b >= l&& tmp.a >= tmp.b)lv3[++cnt3] = tmp;
    else if (tmp.a >= l&&tmp.b >= l)lv4[++cnt4] = tmp;
  }
  sort(lv1 + 1, lv1 + cnt1 + 1);
  sort(lv2 + 1, lv2 + cnt2 + 1);
  sort(lv3 + 1, lv3 + cnt3 + 1);
  sort(lv4 + 1, lv4 + cnt4 + 1);
  printf("%d\n", cnt1 + cnt2 + cnt3 + cnt4);
  for (int i = 1; i <= cnt1; ++i) {
    printf("%08d %d %d\n", lv1[i].id, lv1[i].a, lv1[i].b);
  }
  for (int i = 1; i <= cnt2; ++i) {
    printf("%08d %d %d\n", lv2[i].id, lv2[i].a, lv2[i].b);
  }
  for (int i = 1; i <= cnt3; ++i) {
    printf("%08d %d %d\n", lv3[i].id, lv3[i].a, lv3[i].b);
  }
  for (int i = 1; i <= cnt4; ++i) {
    printf("%08d %d %d\n", lv4[i].id, lv4[i].a, lv4[i].b);
  }
  return 0;
}

