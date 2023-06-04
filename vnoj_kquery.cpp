/*TRYING SO HARD LEARNING HOW TO CODE
APPARENTLY I SUCK */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
#define fr(i,a,b) for(int i = a; i < b; i++) 
#define f(i,a) for(int i = 0; i < a; i++)


/*
// //Only when want to open file
void FileOpen(string s) {
	freopen(s + ".in", "r", stdin);
	freopen(s + ".out", "w", stdout);
}
*/
int const maxn = 30010;
int n, q, x, u, v, k;	
vector<int> st[4 * maxn + 10], a;

void build(int id, int l, int r) {
    if(l == r) {
        st[id].push_back(a[l]);
        return;
    }
    int mid = l + r >> 1;

    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    vector<int>::iterator ptr0 = st[2*id].begin(), ptr1 = st[2*id+1].begin();
    while(ptr0 != st[2*id].end() && ptr1 != st[2*id+1].end()) {
    	if(*ptr0 <= *ptr1) {
    		st[id].push_back(*ptr0);
    		ptr0++;
    	} else {
    		st[id].push_back(*ptr1);
    		ptr1++;
    	}
    }
    if(ptr0 == st[2*id].end()) {
    	while(ptr1 != st[2*id+1].end()) {
    		st[id].push_back(*ptr1);
    		ptr1++;
    	}
    } 
    else {
    	while(ptr0 != st[2*id].end()) {
    		st[id].push_back(*ptr0);
    		ptr0++;
    	}
    }
}

int get(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        return st[id].size() - (upper_bound(st[id].begin(), st[id].end(), k) - st[id].begin());
    }
    int mid = l + r >> 1;
    return get(id*2, l, mid, u, v, k) + get(id*2+1, mid+1, r, u, v, k);
}

void solve() {
	cin >> n;
	a.push_back(0);
	for(int i = 0; i < n ; i++) {
		cin >> x;
		a.push_back(x);
	}
	build(1, 1, n);

	cin >> q;
	for(int i = 0; i < q; i++) {
		cin >> u >> v >> k;
		cout << get(1, 1, n, u, v, k) << endl;
	}
}


signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	solve();
}