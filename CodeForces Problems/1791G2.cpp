#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector <int> >
#define endl '\n'
#define fr(i, a, b) for(int i = a; i < b; i++)

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n, c, idx, minii, cnt, cinTemp;
	vi costs;
	priority_queue<int> tp;
	deque<int> tp2;
	while(tc--) {
		cin >> n >> c;
		costs = vector<int>();
		int mini = 1e18;
		fr(i,0,n) {
			cin >> cinTemp;
			costs.push_back(cinTemp);
			if(cinTemp + i + 1 < mini) {
				mini = cinTemp + i + 1;
				idx = i;
			}
		}
		cout << mini << endl;
		fr(i,0,n) {
			if(i == idx) continue;
			int temp = min(costs[i] + i + 1, costs[i] + n - i);
			tp.push(temp);
		}
		while(!tp.empty()) {
			tp2.push_front(tp.top());
			tp.pop();
		}
		cnt = 0;
		if(c > mini) {
			c -= mini;
			cnt++;
		}
		while(c >= tp2.front() && !tp2.empty()) {
			cnt++; 	
			c -= tp2.front();
			tp2.pop_front();
		}
		cout << cnt << endl;
	}
}