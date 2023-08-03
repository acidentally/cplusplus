#include <bits/stdc++.h>

using namespace std;

#define ar array
#define int long long
#define mod 10
const int MAXN = 1e6 + 5;
const int MOD = 10;
const int INF = 1e9;

template<int _MOD> struct Modular {
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    Modular() { v = 0; }
    Modular(int _v) { v = int((-_MOD < _v && _v < _MOD) ? _v : _v % _MOD); if (v < 0) v += _MOD; }
    friend std::ostream& operator<<(std::ostream& out, const Modular& n) { return out << int(n); }
    friend std::istream& operator>>(std::istream& in, Modular& n) { int v_; in >> v_; n = Modular(v_); return in; }

    friend bool operator==(const Modular& a, const Modular& b) { return a.v == b.v; }
    friend bool operator!=(const Modular& a, const Modular& b) { return a.v != b.v; }
    friend bool operator<(const Modular& a, const Modular& b) { return a.v < b.v; }

    Modular& operator+=(const Modular& m) { if ((v += m.v) >= _MOD) v -= _MOD; return *this; }
    Modular& operator-=(const Modular& m) { if ((v -= m.v) < 0) v += _MOD; return *this; }
    Modular& operator*=(const Modular& m) { v = int((int)v*m.v%_MOD); return *this; }
    Modular& operator/=(const Modular& m) { return (*this) *= inv(m); }
    Modular operator-() const { return Modular(-v); }
    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    friend Modular pow(Modular a, int p) {
        Modular ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; 
    }
    friend Modular inv(const Modular& a) { assert(a.v != 0); return pow(a,_MOD-2); }

    friend Modular operator+(Modular a, const Modular& b) { return a += b; }
    friend Modular operator-(Modular a, const Modular& b) { return a -= b; }
    friend Modular operator*(Modular a, const Modular& b) { return a *= b; }
    friend Modular operator/(Modular a, const Modular& b) { return a /= b; }
    friend Modular operator++(Modular& a, int) { Modular r = a; ++a; return r; }friend Modular operator--(Modular& a, int) { Modular r = a; --a; return r; }
};

template <class T> struct matrix {
    vector<vector<T>> m;
    int r, c;
    matrix() : r(), c() {}
    matrix(int r, int c, T x) : r(r), c(c), m(r, vector<T>(c, x)) {}
    matrix(int n) : matrix(n, n, 0) { // identity matrix
        for (int i = 0; i < n; i++) m[i][i] = 1;
    }
    matrix operator* (matrix<T> b) {
        matrix<T> a = *this;
        assert(a.c == b.r);
        matrix<T> o(a.r, b.c, 0);
        for (int i = 0; i < a.r; i++)
            for (int j = 0; j < b.c; j++)
                for (int k = 0; k < a.c; k++)
                    o.m[i][j] = o.m[i][j] + a.m[i][k] * b.m[k][j];
        return o;
    }
    matrix operator^ (int b) {
        matrix<T> a = *this;
        assert(a.r == a.c);
        matrix<T> o(a.r);
        while (b) {
            if (b % 2) o = o * a;
            a = a * a;
            b /= 2;
        }
        return o;
    }
    void print() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << m[i][j] << " ";
            cout << "\n";
        }
    }
};

using mint = Modular<MOD>;
int a, b;
int solve(int n) {
    n--;
    matrix<mint> A(1, 2, 0); 
    A.m[0][0] = a; A.m[0][1] = b;
    matrix<mint> B(2, 2, 0);
    B.m[0][0] = 0; B.m[0][1] = 1;
    B.m[1][0] = 1; B.m[1][1] = 1;
    A = A * (B ^ n);
    return (int)(A.m[0][0]) - b;
}

int f[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int l, r; cin >> a >> b >> l >> r;
        //cout << "a " << 10 << ' ' << solve(10) << endl;
        int sum1 = solve(l + 1) % mod;
        int sum2 = solve(r + 2) % mod;
        int t = (sum2 - sum1);
        //cout << "a" << ' ' << sum2 << ' ' << sum1 << endl;
        cout << (t + mod) % mod << endl;
    }
}
