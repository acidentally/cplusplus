/**
 *    author:  tourist
 *    created: 11.06.2024 10:41:09
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    int64_t low = 0, high = int64_t(1e12);
    while (low + 1 < high) {
      int64_t mid = (low + high) >> 1;
      int64_t sum = 0;
      for (int i = 0; i < n; i++) {
        sum += ((mid - 1) / c[i] + 1) * a[i];
        sum = min<int64_t>(sum, h);
      }
      if (sum >= h) {
        high = mid;
      } else {
        low = mid;
      }
    }
    cout << high << '\n';
  }
  return 0;
}
