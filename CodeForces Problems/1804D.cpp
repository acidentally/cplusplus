#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	int n, m; cin >> n >> m;
	string s;
	int mini, maxi, minmin = 0, maxmax = 0;
	int consec0, consec11, cnt1;
	for(int i = 0; i < n; i++) {
		cin >> s;
		consec11 = 0; cnt1 = 0; consec0 = 0;
		for(int i = 0; i < m; i++) {
			if(i < m - 1 && s[i] == '1' && s[i + 1] == '1') {
				consec11++;
				cnt1++;
				i++;
			}
			if(s[i] == '1') cnt1++;
		}
		minmin += min(consec11, m/4);
		if(consec11 > m/4) {
			minmin += (consec11 - m/4)*2 + cnt1 - 2*consec11; 
		} else if(consec11 < m/4 || consec11 == m/4) {
			minmin += cnt1 - 2*consec11;
		} 
		for(int i = 0; i < m; i++) {
			if(i < m - 1 && s[i] == '1' && s[i + 1] == '0') {
				consec0++;
				i++;
			}
			else if(i < m - 1 && s[i] == '0') {
				consec0++;
				i++;
			}
		}
		maxmax += cnt1 - max(0ll, m/4-min(m/4, consec0));	
	}
	cout << minmin << ' ' << maxmax;
}