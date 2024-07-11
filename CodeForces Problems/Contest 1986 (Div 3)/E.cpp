/*
Good luck for those who are trying your best
May the most glorious victory come
File name: E.cpp
Code by : acident / lckintrovert
Created since : 24/06/2024 ~~ 12:12:19
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
int const mod       =       1e9 + 7;
int const maxn      =       2e5 + 10;
int const INF       =       1e18;

int n, k, x;
int arrLeft[maxn] = {}, arrRight[maxn] = {};
inline void solve() {
    cin >> n >> k;
    map< int, vector<int> > m;
    for(int i = 1; i <= n; i++){
        cin >> x;
        m[x % k].pb(x);
    }
    int cnt = 0, ans = 0, maxi = 0;
    for(auto s : m) {
        int right = 0, n1 = s.se.size(), cur;
        sort(all(s.se));
        if(n1 & 1) cnt++;
        for(int i = 0; i < n1 - 2; i += 2) {
            cur = arrLeft[i] = s.se[i + 1] - s.se[i] + ((i >= 2) ? arrLeft[i - 2] : 0);
            arrRight[i + 1] = s.se[i + 1] - s.se[i + 2];
        }
        // for(int i = 0; i < n1 - 2; i += 2) {
        //     cout << arrLeft[i] << ' ';
        // }
        arrRight[n1] = 0;
        int preRight = 0;

        for(int i = n1 - 1; i >= 2; i -= 2) {
            preRight += arrRight[i + 1];
            minimize(cur, arrLeft[i - 2] + preRight);
            minimize(cur, preRight + s.se[i] - s.se[i - 2] + ((i >= 4) ? arrLeft[i - 4] : 0));
            cerr << preRight << ' ' << cur << endl;
        }
        minimize(cur, preRight + arrRight[1]);
        ans += cur;
    }
    if(cnt > (n & 1)) {cout << -1; return;}
    else cout << ans/k;
    
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) {
        solve(); cout << endl;
    }
}

/*A place to scribble thoughts

*/