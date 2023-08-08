/*
Good luck for those who are trying your best
May the most glorious victory come
File name: divi.cpp
Code by : acident / lckintrovert
Created since : 08/08/2023 ~~ 15:12:45
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
int const maxn      =       3e5 + 10;
int const INF       =       1e18;
 
int n, k;
int cnt[maxn] = {};
void solve1() {
    cnt[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(i != 1) cnt[i] = 2;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) cnt[i] += 2;
            if(j * j == i) cnt[i]--;
        }
    }
    int d = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(k * cnt[i] * cnt[j] == i * j) d++;
        }
    }
    cout << d;
    // cout << cnt[6] << ' ' << cnt[8] << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    cin >> n >> k;
    solve1();
    // else solve2();
}