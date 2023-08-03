/**
 * File              : 877B.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 15.07.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}void __print(long x) {cerr << x;}void __print(long long x) {cerr << x;}void __print(unsigned x) {cerr << x;}void __print(unsigned long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}void __print(float x) {cerr << x;}void __print(double x) {cerr << x;}void __print(long double x) {cerr << x;}void __print(char x) {cerr << '\'' << x << '\'';}void __print(const char *x) {cerr << '\"' << x << '\"';}void __print(const string &x) {cerr << '\"' << x << '\"';}void __print(bool x) {cerr << (x ? "true" : "false");}template<typename T, typename V>void __print(const pair<T, V> &x);template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}template<typename T, typename V>void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}void _print() {cerr << "]\n";}template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...)     cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}

signed main() {
  TLE;
  string s; cin >> s;
  int n = sz(s);
  int preA[n + 2], preB[n + 2];
  s = ' ' + s;
  preA[0] = preB[0] = 0;
  for(int i = 1; i <= n; i++) {
    preA[i] = preA[i - 1] + (s[i] == 'a');
    preB[i] = preB[i - 1] + (s[i] == 'b'); 
  }
  preA[n + 1] = preA[n];
  preB[n + 1] = preB[n];
  int ans = 0;
  if(preB[n] == 0 || preA[n] == 0) {
    cout << n; return 0;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      int midB = preB[j] - preB[i - 1];
      int leftA = preA[i - 1];
      int rightA = preA[n + 1] - preA[j];
      dbg(i, j, leftA, midB, rightA);
      ans = max(ans, leftA + midB + rightA);
    }
  }
  cout << ans;
}

