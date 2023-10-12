/*
Good luck for those who are trying your best
May the most glorious victory come
File name: D.cpp
Code by : acident / lckintrovert
Created since : 26/09/2023 ~~ 09:06:50
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
const int mod       =        998244353;
const int maxn      =        3e5 + 10;
const int INF       =        1e18;

int n, x;
int bit[35][maxn] = {}, realAns = 0;
inline void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        for(int j = 0; j <= 30; j++) {
            bit[j][i] = bit[j][i - 1];
            if(x & (1 << j)) bit[j][i]++;
        }
    }
    for(int j = 0; j <= 30; j++) {
        int sumOdd = 0, sumEven = 0;
        int countOdd = 0, countEven = 1;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(bit[j][i] & 1) {
                (ans += ((countEven * i) % mod) - (sumEven % mod)) %= mod;
                countOdd++;
                sumOdd += i;
            }
            else {
                (ans += ((countOdd * i) % mod) - (sumOdd % mod)) %= mod;
                countEven++;
                sumEven += i;
            }
        }           
        (realAns += (ans % mod) * (1 << j)) %= mod;
    }
    cout << (realAns + 10000 * mod) % mod;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/