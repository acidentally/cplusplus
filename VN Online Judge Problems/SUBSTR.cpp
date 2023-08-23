/*
Good luck for those who are trying your best
May the most glorious victory come
File name: SUBSTR.cpp
Code by : acident / lckintrovert
Created since : 21/08/2023 ~~ 14:41:46
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
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
int const base      =       31;
 
string A, B;
int modPow[maxn] = {}, HashA[maxn] = {};
int getHash(int i, int j) {
    return ((HashA[j] - HashA[i - 1] * modPow[j - i + 1] + 1000000000 * mod) % mod);
}
void solve() {
    getline(cin, A);
    getline(cin, B);
    int lenA = A.size(), lenB = B.size();
    A = ' ' + A;
    B = ' ' + B;
    modPow[0] = 1;
    for(int i = 1; i <= lenA; i++) {
        modPow[i] = (modPow[i - 1] * base) % mod;
    }
    HashA[0] = 0;
    for(int i = 1; i <= lenA; i++) {
        HashA[i] = (HashA[i - 1] * base + A[i] - 'a') % mod;
    }
    int HashB = 0;
    for(int i = 1; i <= lenB; i++) {
        HashB = (HashB * base + B[i] - 'a') % mod;
    }
    for(int i = 1; i <= lenA - lenB + 1; i++) {
        if(getHash(i, i + lenB - 1) == HashB) cout << i << ' ';
    }
    return;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}