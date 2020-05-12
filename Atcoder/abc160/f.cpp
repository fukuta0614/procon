// abc160_f
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


const int mod = 1e9 + 7;
struct mint {
    ll x;
    mint(ll a=0){x = a>=0 ? a%mod : mod-(-a)%mod;}
    mint(const mint& m):x(m.x){}
    mint& operator+=(const mint& a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator+=(const int& a) { if ((x += a) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint& a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const int& a) { if ((x += mod-a) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint& a) { (x *= a.x) %= mod; return *this; }
    mint& operator*=(const int& a) { (x *= a) %= mod; return *this; }
    mint operator+(const mint& a) const { mint res(*this); return res+=a; }
    mint operator+(const int& a) const { mint res(*this); return res+=a; }
    mint operator-(const mint& a) const { mint res(*this); return res-=a; }
    mint operator-(const int& a) const { mint res(*this); return res-=a; }
    mint operator-() const {mint res(*this); return mint(0)-res;}
    mint operator*(const mint& a) const { mint res(*this); return res*=a; }
    mint operator*(const int& a) const { mint res(*this); return res*=a; }
    bool operator==(const mint& a) const { return x == a.x;}
    bool operator==(const int& a) const { return x == a;}
    bool operator!=(const mint& a) const { return x != a.x;}
    bool operator!=(const int& a) const { return x != a;}
    operator bool() const {return x>0;}

    mint pow(ll t) const {mint r=1,a=*this; do{if(t&1)r*=a;a*=a;}while(t>>=1);return r;}
    mint pow(mint t) const {mint r=1,a=*this; do{if(t.x&1)r*=a;a*=a;}while(t.x>>=1);return r;}
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
    mint& operator/=(const int& a) { return (*this) *= mint(a).inv(); }
    mint operator/(const mint& a) const { mint res(*this); return res/=a; }
    mint operator/(const int& a) const { mint res(*this); return res/=a; }

    friend ostream& operator<<(ostream& os, const mint& m) {cout << m.x; return os;}
    friend istream& operator>>(istream& is, mint& m) { return is >> m.x; }
};

// 階乗
struct Factorial {
    vector<mint> values;
    explicit Factorial(int n): values(n+1, 0) { values[0] = 1; for (int i = 1; i <= n; ++i) { values[i] = values[i-1] * i;}}
    mint operator()(int n){ return n >= 0 ? values[n] : mint(0);}
};

// 組み合わせ
mint nCk(int n, int k, Factorial& f){ return n != k ? f(n) / (f(n-k) * f(k)) : mint(1);}

using P = pair<mint, int>;

struct Graph {

    int n;
    vector<vector<int>> edges;
    Factorial f;

    vector<P> memo;
    vector<mint> ans_memo;

    Graph(int n_): n(n_), edges(n_), memo(n_), ans_memo(n_), f(2*n_+1) {}

    void add_edge(int u, int v){
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    P dfs(int u = 0, int p = -1) {

        mint cnt = 1;
        int len = 0;
        for (auto v: edges[u]){
            if (v == p) continue;

            P res = dfs(v, u);
            mint comb = res.first;
            int sz = res.second;

            cnt = cnt * comb * nCk(len+sz, len, f);
            len += sz;
        }

        return memo[u] = P(cnt, len+1);
    }

    void dfs2(int u = 0, int p = -1) {

        if (p == -1){
            ans_memo[u] = memo[u].first;
        } else {
            mint cur_comb = memo[u].first;
            int cur_sz = memo[u].second;

            mint par_comb = ans_memo[p];
//            mint rev_comb = par_comb / cur_comb / nCk(n-1, cur_sz, f);
//            ans_memo[u] = cur_comb * rev_comb * nCk(n-1, cur_sz-1, f);
            ans_memo[u] = par_comb * mint(cur_sz) / mint(n-1-(cur_sz-1)); // 上を単純化しただけ

        }

        for (auto v: edges[u]){
            if (v == p) continue;
            dfs2(v, u);
        }
    }

};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;

    Graph g(N);

    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g.add_edge(a, b);
    }

    g.dfs(0);

    g.dfs2(0);

    REP(i, N){
        print(g.ans_memo[i]);
    }


    return 0;
}
