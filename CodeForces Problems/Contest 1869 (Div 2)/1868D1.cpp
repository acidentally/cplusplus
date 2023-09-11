/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1868D1.cpp
Code by : acident / lckintrovert
Created since : 10/09/2023 ~~ 21:57:50
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
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       2e5 + 10;
int const INF       =       1e18;
 
int n, sum;
int a[maxn] = {};
pi cur;
pi compute(int k, int have) { 
    if(k == 0) return mp(0, 0);
    if(k > 0) {
        //give - take = k -> take = give - k;
        for(int g_ = 0; g_ < 30; g_++) {
            int t_ = (1 << g_) - k;
            if(t_ <= 0 || __builtin_popcount(t_) != 1 || g_ > have + t_) continue;
            int g = -1;
            while(t_) {
                g++;
                t_ >>= 1;
            }
            return mp(g_, g);
        }
        return mp(-1, -1);
    }
    else {
        k = -k; 
        for(int t_ = 0; t_ < 30; t_++) {
            int g_ = (1 << t_) - k;
            if(g_ <= 0 || __builtin_popcount(g_) > 1 || g_ > have + t_) continue;
            int g = -1;
            while(g_) {
                g++;
                g_ >>= 1;
            }
            return mp(g, t_);
        }
        return mp(-1, -1);
    }
}
int give[50] = {}, take[50] = {};   
void solve() {
    cin >> n;
    sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n != 0) {
        NO;
        return;
    }  
    for(int i = 0; i < 31; i++) give[i] = take[i] = 0;
    sum /= n;
    for(int i = 1; i <= n; i++) {
        cur = compute(a[i] - sum, a[i]);  
        if(cur.fi == -1) {
            NO;
            return;
        }
        give[cur.fi]++;
        take[cur.se]++;
    }
    for(int i = 0; i < 31; i++) {
        if(give[i] != take[i]) {
            NO;
            return;
        }
    } 
    YES;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}

/*A place to scribble thoughts

*/

