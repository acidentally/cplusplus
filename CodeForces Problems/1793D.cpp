#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int cinTemp;

	vector<int> posp(n + 1), posq(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> cinTemp;
		posp[cinTemp] = i;
	}
	for(int i = 1; i <= n; i++) {
		cin >> cinTemp;
		posq[cinTemp] = i;
	}
	int l = min(posp[1], posq[1]), r = max(posp[1], posq[1]);
 	int mini, maxi;
	int minlq, maxrq, minlp, maxrp;

	int res = 0;
	res += (l - 1) * l / 2 
		+ (n - r) * (n - r + 1) / 2 + (r - l - 1) * (r - l) / 2;

	for(int i = 2; l > 1 || r < n; i++) {
		
		if((posp[i] >= l && posp[i] <= r) || (posq[i] >= l && posq[i] <= r)) {
			l = min(l, min(posp[i], posq[i]));
			r = max(r, max(posp[i], posq[i]));
			
			continue;
		}
		if(posp[i] > r) {
			maxrp = posp[i] - 1;
			minlp = 1;
		} else if(posp[i] < l){
			maxrp = n;
			minlp = posp[i] + 1;
		}

		if(posq[i] > r) {
			maxrq = posq[i] - 1;
			minlq = 1;
		} else if(posq[i] < l){
			maxrq = n;
			minlq = posq[i] + 1;
		}

		mini = max(minlp, minlq);

		maxi = min(maxrp, maxrq);

		res += (l - mini + 1) * (maxi - r + 1);
		l = min(l, min(posp[i], posq[i]));
		r = max(r, max(posp[i], posq[i]));

	}
	cout << res + 1;
}



