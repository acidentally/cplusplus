/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1978C.cpp
Code by : acident / lckintrovert
Created since : 16/06/2024 ~~ 17:14:14
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
#define YES                 cout << "Yes\n"
#define NO                  cout << "No\n"
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

int n, k, p[maxn] = {}, tc;
inline void solve() {
    cin >> n >> k;
    int left = 1, right = n;
    int kmax = 0;
    for(int i = n, j = 1; i >= 1; i--) {
        p[i] = i;
        kmax += abs(i - j++);
    }
    if(k % 2 == 1 || k > kmax) {
        NO;
        return;
    }
    YES;
    k /= 2;
    while(k > 0) {
        if(right - left > k) left++;
        else if(right - left <= k) {
            swap(p[left], p[right]);
            k -= right - left;
            right--; left++;
        }
    }
    int value = 0;
    for(int i = 1; i <= n; i++) {
        value += abs(a[i] - i);
    } cout << value - k;
    for(int i = 1; i <= n; i++){
        cout << p[i] << ' ';
    } cout << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    cin >> tc;
    while(tc--) solve();
}

/*A place to scribble thoughts

*/