/*
Good luck for those who are trying your best
May the most glorious victory come
File name: vnoj_vpc23_d.cpp
Code by : acident / lckintrovert
Created since : 04/08/2023 ~~ 13:13:11
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define vvi                 vector< vector<int> >
#define endl                '\n'
#define pb                  emplace_back
#define pf                  push_front
#define all(a)              a.begin(), a.end()
#define mp                  make_pair
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define ins                 insert
#define double              long double
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<double, pi>    pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
 
struct point {
    int x, y;
    point() : x(0), y(0) {}
    point(int x_, int y_) : x(x_), y(y_) {}
};
struct DSU {
	vi p;
	DSU() : p(maxn) {}
	DSU createDSU(int l) {
		DSU tem;
		for(int i = 0; i <= l; i++) tem.p[i] = i;
		return tem;
	}
	int find(int v) {
        if(v == p[v]) return v;
        return p[v] = find(p[v]);
    }
    void connect(int u, int v) {
    	u = find(u); v = find(v);
    	p[u] = v;
    }
}g1;

int n;
double w, c;
point a[200] = {};
priority_queue<pii, vector<pii>, greater<pii> > q, q2;
double sqr(int k) {
    return (dub)k * k;
}
double dis(point A,  point B) {
    return c * sqrt(sqr(A.x - B.x) + sqr(A.y - B.y));
}  
void solve() {
    cin >> n;
    g1 = g1.createDSU(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    cin >> w >> c;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            q.push(mp(dis(a[i], a[j]), mp(i, j)));
        }
    }
    double ans1 = 0, ans2 = 0;
    int tplt = n;
    while(!q.empty() && tplt != 1) {
        double dis = q.top().fi;
        int u = q.top().se.fi, v = q.top().se.se;
        q.pop();
        if(g1.find(u) == g1.find(v)) continue;
        ans1 += dis;
        g1.connect(u, v);
        q2.push(mp(dis, mp(u, v)));
        tplt--;
    }
    tplt = n + 1;
    g1 = g1.createDSU(n + 1);
    for(int i = 1; i <= n; i++)  {
        q2.push(mp(w, mp(0, i)));
    }
    while(!q2.empty() && tplt != 1) {
        double dis = q2.top().fi;
        int u = q2.top().se.fi, v = q2.top().se.se;
        q2.pop();
        if(g1.find(u) == g1.find(v)) continue;
        ans2 += dis;
        g1.connect(u, v);
        tplt--;
    }
    cout << fixed << setprecision(9) << min(ans1, ans2);
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}