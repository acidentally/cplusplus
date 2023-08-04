/*
Good luck for those who are trying your best
May the most glorious victory come

File name: BDuongHe_caesar.cpp
Code by : acident / lckintrovert
Created since : 2023-08-04 ~~ 08:47:32
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
int const mod          =    1e8;
int const maxn         =    200;
int const INF          =    LLONG_MAX;

int n1, n2, k1, k2;
void solve() {
    cin >> n1 >> n2 >> k1 >> k2;
    k1++; k2++;
    //compute (n1 + n2)! / n1! / n2! mod 1e8 là tổng sắp xếp n1 n2 thằng
    //đếm xem có bao nhiêu permutation mà k1 thằng kia đứng cạnh, k2 thằng kia đứng cạnh
    //rồi trừ cho phần giao của cả 2 
    if(n1 < n2) swap(n1, n2);
    int ans = 1, idx = 1;
    for(int i = 51; i <= 100; i++) {
        cerr << ans <<
        ans = (ans * i / idx);
        idx++;
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}