/*
Good luck for those who are trying your best
May the most glorious victory come
File name: palinprime.cpp
Code by : acident / lckintrovert
Created since : 08/08/2023 ~~ 14:09:41
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
int const maxn      =       99999;
int const INF       =       1e18;
 
bool isPrime[200] = {};
void eratos() {
    isPrime[0] = isPrime[1] = 1;
    for(int i = 2; i <= 150; i++) {
        if(!isPrime[i]) {
            for(int j = i * i; j <= 150; j += i) {
                isPrime[j] = 1;
            }
        }
    }
}
int sumDig(int k) {
    int sum = 0;
    while(k) {
        sum += k % 10;
        k /= 10;
    }
    return sum;
}
string concat(int k, int dig) {
    int k_ = k;
    string ans = "";
    while(k) {
        ans = (char)(k % 10 + '0') + ans;
        k /= 10;
    }
    ans = ans + (char)(dig + '0');
    while(k_) {
        ans = ans + (char)(k_ % 10 + '0');
        k_ /= 10;
    }
    return ans;
}
bool cmp(string a, string b) {
    if(a.size() < b.size()) return 1;
    if(a.size() > b.size()) return 0;
    if(a <= b) return 1;
    return 0;
}
string rev(int k) {
    int k_ = k;
    string ans = "";
    while (k)
    {
        ans = (char)(k % 10 + '0') + ans;
        k /= 10;
    }
    while (k_)
    {
        ans = ans + (char)(k_ % 10 + '0');
        k_ /= 10;
    }
    return ans;
}
bool check[maxn] = {};
int d = 0;
string l, r;
void solve() {
    cin >> l >> r;
    int k = r.size();
    int maxi = 1;
    for(int i = 1; (i << 1) < r.size();i++) {
        maxi = (maxi << 3) + (maxi << 1);
    }
    if(cmp(l, "11") && cmp("11", r)) d++;
    if(cmp(l, "7") && cmp("7", r)) d++;
    if(cmp(l, "5") && cmp("5", r)) d++;
    if(cmp(l, "3") && cmp("3", r)) d++;
    if(cmp(l, "2") && cmp("2", r)) d++;
    for(int i = 10; i <= 1000000; i *= 10) {
        string temp = rev(i);
        if(cmp(l, temp) && cmp(temp, r)) {
            d++; 
        }
    }
    // cout << d;
    for(int i = 1; i <= maxi; i++) {
        string temp = concat(i, 0);
        if (!isPrime[2 * sumDig(i)] && cmp(l, temp) && cmp(temp, r)) {
            d++;
        }

        for(int j = 1; j <= 9; j += 2) {
            string temp = concat(i, j);
            if(!isPrime[2 * sumDig(i) + j] && cmp(l, temp) && cmp(temp, r)) {
                d++;
            }
        }
    }
    // cout << concat(1, 1);
    cout << d;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    eratos();
    //File?
    solve();
}