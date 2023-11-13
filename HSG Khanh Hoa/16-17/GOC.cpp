/*
Good luck for those who are trying your best
May the most glorious victory come
File name: GOC.cpp
Code by : acident / lckintrovert
Created since : 09/11/2023 ~~ 06:43:21
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
const int maxn      =        20;
const int INF       =        1e18;

int n, k, x;
bool ans[361] = {};
inline void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        int temp = x;
        ans[x] = 1;
        (temp += x) %= 360;
        while(temp != x) {
            // cout << temp << ' ';
            ans[temp] = 1;
            (temp += x) %= 360;
        }
        // cout << endl;
    }
    for(int i = 1; i <= k; i++) {
        cin >> x;
        bool found = false;
        for(int j = 0; j < 360; j++) {
            if(j + x >= 360) continue;
            if(ans[j + x] && ans[j]) {cout << "YES" << endl; found = true; break;}
        }
        if(!found) cout << "NO" << endl;
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/