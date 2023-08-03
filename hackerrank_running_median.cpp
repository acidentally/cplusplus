/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define dub 			double
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				emplace_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";

typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;

int const maxn 		= 	1e5 + 10; 
int const INF 		= 	LLONG_MAX;

int n, x1, x2;
priority_queue<int> L;
priority_queue<int, vi, greater<int> > R;
void solve() {
	cin >> n;
	cin >> x1;
	// L.push(-INF); R.push(INF);
	double curMed = x1;
	cout << fixed << setprecision(1) << double(x1) << endl;

	double ans = 0;
	for(int i = 2; i <= n; i++) {
		cin >> x2;
		if(!(i & 1)) { //i chẵn tức là median có 2 phần tử
			if(L.empty() && R.empty()) {
				cout << fixed << setprecision(1) << double(x2 + curMed)/2.0 << endl;
				L.push(min((double)x2, curMed));
				R.push(max((double)x2, curMed));
			}
			else {
				if(x2 >= R.top()) {
					R.push(x2);
					x2 = R.top();
					R.pop();
				}
				else {
					L.push(x2);
					x2 = L.top();
					L.pop();
				}
				// cout << i << ' ' << curMed << ' ' << R.top() << ' ';
				cout << fixed << setprecision(1) << double(x2 + curMed)/2.0 << endl;
				L.push(min(double(x2), curMed));
				R.push(max(double(x2), curMed));
 			}
		}
		else {
			if(x2 >= R.top()) {
				R.push(x2);
				curMed = R.top();
				R.pop();
			}
			else {
				L.push(x2);
				curMed = L.top();
				L.pop();
			}
			cout << fixed << setprecision(1) << (double)curMed << endl;
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}