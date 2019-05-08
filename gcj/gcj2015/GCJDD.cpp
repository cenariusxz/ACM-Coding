#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int r, c;
int a[42][42];
set < vector <int> > s;

void dfs(int i, int j) {
  if (i == r) {
    vector <int> z;
    for (int rot = 0; rot < c; rot++) {
      z.clear();
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          z.push_back(a[i][(rot + j) % c]);
        }
      }
      if (s.find(z) != s.end()) {
        return;
      }
    }
    s.insert(z);
    return;
  }
  for (int d = 1; d <= 3; d++) {
    a[i][j] = d;
    bool ok = true;
    for (int x = 0; x < r; x++) {
      for (int y = 0; y < c; y++) {
        if (a[x][y] == -1) {
          continue;
        }
        int empty = 0, good = 0;
        for (int q = 0; q < 4; q++) {
          int xk = x + dx[q];
          int yk = y + dy[q];
          if (yk < 0) yk += c;
          if (yk >= c) yk -= c;
          if (xk < 0 || xk >= r) continue;
          if (a[xk][yk] == a[x][y]) good++;
          if (a[xk][yk] == -1) empty++;
        }
        if (good > a[x][y] || good + empty < a[x][y]) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        break;
      }
    }
    if (ok) {
      if (j + 1 < c) {
        dfs(i, j + 1);
      } else {
        dfs(i + 1, 0);
      }
    }
    a[i][j] = -1;
  }
}

int main() {
  freopen("D-small-attempt1.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        a[i][j] = -1;
      }
    }
    s.clear();
    dfs(0, 0);
    printf("%d\n", s.size());
    fflush(stdout);
    cerr << "test case " << qq << " done" << endl;
  }
  return 0;
}
