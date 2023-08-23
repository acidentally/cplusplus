/*
Good luck for those who are trying your best
May the most glorious victory come
File name: vnoj_contesttraining_ptbh.cpp
Code by : acident / lckintrovert
Created since : 20/08/2023 ~~ 20:09:58
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
int const maxn      =       1e9 + 10;
int const INF       =       1e18;
 
int n;
int compute(int k) {
    int k_ = k, sum = 0;
    while(k_) {
        sum += k_ % 10;
        k_ /= 10;
    }
    return k * (k + sum);
}
void solve() {
    cin >> n;
    int test = (int)sqrt(n);
    for(int i = max(1ll, test - 10000); i <= test; i++) {
        if(compute(i) == n) {
            cout << i;
            return;
        }
    }
    cout << -1;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}