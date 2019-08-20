// abc135_f
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../cxx-prettyprint/prettyprint.hpp"
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF ((1 << 29)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


template <typename T=long long, T base1=1009, T base2=1007, T mod1=1000000007, T mod2=1000000009>
struct RollingHash {
    using hash_type = pair<T,T>;
    vector<T> hash1, hash2;
    vector<T> pow1, pow2;

    explicit RollingHash(const string &s) {
        auto n = (int)s.size();

        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1,1);
        pow2.assign(n+1,1);

        for(int i=0;i<n;i++) {
            hash1[i+1] = (hash1[i] * base1 + s[i]) % mod1;
            hash2[i+1] = (hash2[i] * base2 + s[i]) % mod2;
            pow1[i+1] = pow1[i] * base1 % mod1;
            pow2[i+1] = pow2[i] * base2 % mod2;
        }
    }

    hash_type get(int l,int r) {
        T t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        T t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return make_pair(t1, t2);
    }

    // ハッシュ値がh1の文字列の末尾に、長さh2_lenでハッシュ値がh2をくっつけた文字列のハッシュ値
    hash_type concat(hash_type h1, hash_type h2, int h2_len) {
        assert(h2_len < pow1.size());
        T t1 = (h1.first * pow1[h2_len] + h2.first) % mod1;
        T t2 = (h2.first * pow2[h2_len] + h2.first) % mod2;
        return make_pair(t1, t2);
    }
};


struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;
    vector<int> size; // size[i]: iが親なら連結成分の数

    UnionFind(int N) : par(N), rank(N), size(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {par[i] = i; rank[i] = 0; size[i] = 1;}
    }

    int find(int x) { // データxが属する木の根を再帰で得る：find(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = find(x); //xの根をrx
        int ry = find(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま

        // rank[rx] >= rank[ry] となるように rx と ry を swap
        if(rank[rx] < rank[ry]) swap(rx, ry);

        // 同じ高さだったならばまとめたことによって高さ +1
        if(rank[rx] == rank[ry]) ++rank[rx];

        par[ry] = rx; // root rx に ry の木をつなぐ
        size[rx] += size[ry];
        size[ry] = 0;

    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }

    int get_size(int x){
        int rx = find(x);
        return size[rx];
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S, T;
    cin >> S >> T;
    string S_dash = S;

    while (S_dash.size() < S.size() + T.size() - 1){
        S_dash += S;
    }

    auto rHash1 = RollingHash<>(S_dash);
    auto rHash2 = RollingHash<>(T);

    auto uf = UnionFind(S.size());

    auto s = (int)S.size();
    auto t = (int)T.size();
    REP(i, s){
        if (rHash1.get(i, i + t) == rHash2.get(0, t)){
            if (uf.same(i, (i + t) % s)){
                print(-1);
                return 0;
            }
            uf.unite(i, (i + t) % s);
        }
    }

    int ans = 0;
    REP(i, s){
        ans = max(ans, uf.get_size(i));
    }
    print(ans-1);

    return 0;
}
