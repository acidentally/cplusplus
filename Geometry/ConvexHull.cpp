/*
Good luck for those who are trying your best
May the most glorious victory come
File name: ConvexHull.cpp
Code by : acident / lckintrovert
Created since : 23/09/2023 ~~ 07:49:36
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  long long
#define uint                 unsigned long long
#define dub                  double
#define fi                   first
#define se                   second
#define endl                 '\n'
#define pb                   push_back
#define pf                   push_front
#define eb                   emplace_back
#define ins                  insert
#define mp                   make_pair
#define all(a)               a.begin(), a.end()
#define YES                  cout << "YES\n"
#define NO                   cout << "NO\n"
#define coutdub(x)           cout << fixed << setprecision(x)
#define cerrdub(x)           cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
const int mod       =        1e9 + 7;
const int maxn      =        1e5 + 10;
const int INF       =        1e18;

struct point {
    int x = 0, y = 0;
    point() = default;
    point(int x_, int y_) : x(x_), y(y_) {}
};
struct vec {
    int x, y;
    vec() = default;
    vec(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

};
bool ccw(point a, point b, point c) {
    vec v1 = vec(a, b);
    vec v2 = vec(a, c);
    return ((v1.x * v2.y - v1.y * v2.x) > 0);
}
int n, u, v;
vector<point> e, hull;
inline void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        e.pb(point(u, v));
    }
    sort(all(e), [](const point &a, const point &b) {
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    hull.pb(e[0]);
    for(int i = 1; i < n; i++) {
        // cerr << s.x << ' ' << s.y << endl;
        while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), e[i]))
            hull.pop_back();
        hull.pb(e[i]);
    }
    // cerr << "CUR HULL: ";
    // for(auto s : hull) {
    //     cerr << s.x << ' ' << s.y << " --- ";
    // }
    // cerr << endl;
    for(int i = e.size() - 2; i >= 0; i--) {
        // cerr << e[i].x << ' ' << e[i].y << endl;
        while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), e[i])) 
            hull.pop_back();
        hull.pb(e[i]);
    }
    if(n > 1) hull.pop_back();
    cout << hull.size() << endl;
    for(auto s : hull) cout << s.x << ' ' << s.y << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // #ifdef ONLINE_JUDGE
    // freopen("test.INP", "r", stdin);
    // freopen("test.OUT", "w", stdout);
    // #endif //ONLINE JUDGE
    solve();
}

/*A place to scribble thoughts

*/