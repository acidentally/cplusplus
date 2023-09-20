/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 319C.cpp
Code by : acident / lckintrovert
Created since : 20/09/2023 ~~ 17:07:00
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  long long
#define uint                 unsigned long long
#define dub                  long double
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
struct line {
    int A, B;
    line() = default;
    line(int a, int b) : A(a), B(b) {};
    int value(int x) {
        return A * x + B;
    }
};
bool ok(line l1, line l2, line l3) {
    return (dub)(l3.B - l1.B) / (l1.A - l3.A) <= (dub) (l2.B - l1.B) / (l1.A - l2.A);
}
struct CHT {
    vector<line> lines;
    void addLine(line l) {
        while(lines.size() > 1 && ok(lines[lines.size() - 2], lines.back(), l)) {
            lines.pop_back();
        }
        lines.pb(l);
    }
    int query(int x) {
        int ans = 1e18;
        int l = 0, r = lines.size() - 1;
        while(l <= r) {
            int mid = l + r >> 1;
            int cur = lines[mid].value(x);
            minimize(ans, cur);
            if(mid != lines.size() - 1 && cur > lines[mid + 1].value(x)) {
                l = mid + 1;
            } else if(r != 0 && cur > lines[mid - 1].value(x)) {
                r = mid - 1;
            } else return ans;
        } return ans;
    }
};

int n;
int a[maxn], b[maxn] = {};
inline void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    CHT Hulls;
    Hulls.addLine(line(b[1], 0));
    int curdp = 0;
    for(int i = 1; i <= n; i++) {
        curdp = Hulls.query(a[i]);
        Hulls.addLine(line(b[i], curdp));
    }
    cout << Hulls.query(a[n]);
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/