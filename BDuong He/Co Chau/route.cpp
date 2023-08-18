/*
Good luck for those who are trying your best
May the most glorious victory come
File name: route.cpp
Code by : acident / lckintrovert
Created since : 18/08/2023 ~~ 09:15:34
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
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       200;
int const INF       =       1e18;

int abso(int x, int y) {
    return max(x - y, y - x);
}

struct point {
    int x, y;
    point() : x(0), y(0) {}
    point(int x_, int y_) : x(x_), y(y_), {}
    int dis(point A, point B) {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }
};

int n;
point a[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}