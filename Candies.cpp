#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e5;
priority_queue<int> sorted;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int sum, cur, cinTemp;
	// freopen("in.in", "r", stdin);
	// freopen("out.out", "w", stdout);
	while(tc--) {
		int n; cin >> n;
		int a[n + 1] = {};
		for(int i = 0; i < n; i++) 	{
			cin >> cinTemp;
			a[cinTemp]++;
		}
		while(!sorted.empty()) sorted.pop();
		
		for(int i = 1; i <= n; i++) {
			if(a[i] != 0) sorted.push(a[i]);
		}
		sum = sorted.top();	
		sorted.pop();
		cur = sum - 1;
		// sum = 0; cur = sorted.top() + 1;
		while(!sorted.empty() && cur > 0) {
			cur = min(cur, sorted.top());
			sum += cur;
			sorted.pop();
			cur--;
		}
		cout << sum;
		if(tc > 0) cout << '\n';
	}
	return 0;
}
// 2 3 4
// sum = 4
// 2 3
// cur = 3
// cur = 3
// 2
// sum = 7
// cur = 2
// cur = 2
// sorted empty
// sum + cur = 9
// cur = 1

