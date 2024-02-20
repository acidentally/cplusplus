/*
Good luck for those who are trying your best
May the most glorious victory come
File name: E.cpp
Code by : acident / lckintrovert
Created since : 27/01/2024 ~~ 22:11:04
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
const int maxn      =        2e5 + 10;
const int INF       =        1e18;

int n, a, ans = 0, tem;
stack<int> q;
inline void solve() {
    cin >> n;
    q.push(0);
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(a >= q.top()) {
            // cerr << a << ' ' << q.top() << endl;
            ans += a - q.top(); 
            q.push(a);
        }
        else if(a < q.top()) {
            while(a < q.top()) q.pop();
            q.push(a);
        }
        // cerr << ans << endl;
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/