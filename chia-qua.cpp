/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

int m, n, k;
int solve() {
	cin >> m >> n >> k;
	if(m < n) swap(m, n);
	//Tóm tắt :
	//Cắt a <= m - 1, b <= n - 1
	//Maximise (a + 1) * (b + 1);
	//Tìm a <= m, b <= n;
	// Max a * b? : a + b = k + 2;
	//a^2 + 2ab + b^2 = c
	k += 2;
	int a = k/2, b = k - a;
	if(k >= 2 * n) {
		
	}
	

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
}