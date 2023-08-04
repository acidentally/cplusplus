#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector <int> >
#define endl '\n'
#define fr(i, a, b) for(int i = a; i < b; i++)

priority_queue<int> tp, temp;
deque<int> tp2, minFirst;

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n, c, cinTemp, cnt;
	while(tc--) {
		tp = temp = priority_queue<int>();
		tp2 = minFirst = deque<int>();
		cin >> n >> c;

		for(int i = 1; i <= n; i++) {
			cin >> cinTemp;
			tp.push(min(cinTemp + i, cinTemp + n + 1 - i));
			temp.push(cinTemp + i);
		}

		for(int i = 1 ; i <= n; i++){
			tp2.push_front(tp.top());
			minFirst.push_front(temp.top());
			tp.pop(); temp.pop();
		}
		cnt = 0;
		if(c > minFirst.front()) {
			c -= minFirst.front();
			cnt = 1;
		}
		while(c >= tp2.front() && !tp2.empty()) {
			cnt++; 	
			c -= tp2.front();
			tp2.pop_front();
		}
		cout << cnt << endl;
	}
}