/*
Good luck for those who are trying your best
May the most glorious victory come
File name: tonguocv2.cpp
Code by : acident / lckintrovert
Created since : 08/08/2023 ~~ 17:26:20
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
int const maxn      =       2e5 + 10;       
int const INF       =       1e18;
 
vi minPrime(INF, 0);
void eratos() {
    minPrime[0] = minPrime[1] = 1;
    for(int i = 2; i * i <= INF; i++) {
        if(minPrime[i] == 0) {
            for(int j = i * i; j <= INF; j += i) {
                if(minPrime[j] == 0) minPrime[j] = i;
            }
        }
    }
    for(int i = 2; i <= INF; i++) {
        if(minPrime[i] == 0) minPrime[i] = i;
    }
}

int sqr(int k) {
    return k * k;
}
int modPow(int a, int k) {
    if(k == 0) return 1;
    if(k == 1) return a;
    if(k & 1) return a * sqr(modPow(a, k >> 1));
    return sqr(modPow(a, k >> 1));
}
int n, a[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; //Đếm tổng ước của a[i];
        //nếu a[i] = pow(p1, x1) * pow(p2, x2) * ... * pow(pk, xk)
        //Thì ans = PI((pow(p1, x1) - 1) / (p1 - 1));

        //C1 : Brute force
        if(a[i] == 1) cout << 1 << ' ';
        else {
            int ans = 2;
            for(int j = 2; j * j <= a[i]; j++) {
                if(a[i] % j == 0) ans += 2;
                if(j * j == a[i]) ans -= 1;
            }
            cout << ans << ' ';
        }

        //C2 : Theo cthuc
        vector<pi> a;
        while(a[i] > 1) {
            int cur = minPrime[a[i]], pow = 0;
            while(a[i] % cur == 0) {
                pow++;
                a[i] /= cur;
            }
            a.pb(mp(cur, pow));
        }
        int ans = 1;
        for(auto s : a) {
            //ans *= (pow(s.fi, s.se + 1) - 1) / (s.fi - 1);
            ans *= modPow(s.fi, s.se + 1);
            ans /= s.fi - 1;
        }

        //C3 :
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}