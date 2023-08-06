/*
Good luck for those who are trying your best
May the most glorious victory come
File name: CF_1856B.cpp
Code by : acident / lckintrovert
Created since : 06/08/2023 ~~ 10:48:06
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
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, a[maxn] = {};
void solve() {
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum < n + n / 2) {
        NO 
        return;
    }
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] == 1) {
            sum -= 2;
            cnt++;
        } else sum -= 1;
    }
    // cerr << sum << endl;
    if(sum <= 0) NO  
    else if(sum == a[n] && (cnt == 0 || a[n] == 1)) NO
    else YES
}   
main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}