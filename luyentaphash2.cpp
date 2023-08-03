#include <bits/stdc++.h>

using namespace std;

#define int long long 

int n, a[300001], vis[300001], cnt[600001];

struct td {
    int l, r, v;
    td() {}
    td(int left, int right, int value): l(left), r(right), v(value) {}
};

int main() {
	int n;
   	cin >> n;

    deque < td > que;
	int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        while (vis[a[i]]) {
            td cur = que.front();
            que.pop_front();
            vis[a[cur.l]] = 0;
            cnt[cur.v + cur.l - 1]--;
            if (cur.l != cur.r) que.push_front(td(cur.l + 1, cur.r, cur.v)), cnt[cur.v + cur.l]++;
        }

        int ml = i;

        while (!que.empty() && que.back().v < a[i]) {
            ml = que.back().l;
            cnt[que.back().v + que.back().l - 1]--;
            que.pop_back();
        }

        que.push_back(td(ml, i, a[i]));
        vis[a[i]] = 1;
        cnt[ml + a[i] - 1]++;
        ans += cnt[i];
    }
	
	cout << ans;
    return 0;
}