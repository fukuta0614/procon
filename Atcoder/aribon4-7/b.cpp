// aribon4-7_b
// Japan Alumni Group Summer Camp 2015 Day 2 F ほぼ周期文字列
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
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;


template <typename T=long long, T base1=1009, T base2=1007, T mod1=1000000007, T mod2=1000000009>
struct RollingHash {
    using hash_type = pair<T,T>;
    vector<T> hash1, hash2;
    vector<T> pow1, pow2;
    string S;

    explicit RollingHash(const string &s): S(s) {
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
        T t2 = (h2.second * pow2[h2_len] + h2.second) % mod2;
        return make_pair(t1, t2);
    }

    // idx番目の文字をcに変えたときの、[l,r)のハッシュ
    hash_type get_changed_one_char(int l, int r, int idx, char c){
        T t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        T t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        if (l <= idx && idx < r) {
            t1 = ((t1 + (c - S[idx]) * pow1[r-idx-1]) % mod1 + mod1) % mod1;
            t2 = ((t2 + (c - S[idx]) * pow2[r-idx-1]) % mod2 + mod2) % mod2;
        }
        return make_pair(t1, t2);
    }

    // l..l+dとr..r+dの文字列が一致しているか
    bool is_same(int l, int r, int d){
        return get(l, l+d) == get(r, r+d);
    }

    // l..l+dとr..r+dの文字列が一文字を除き一致しているか
    bool is_same_except_one(int l, int r, int d){
        // 少なくともどこまで一致しているかを求めて、
        // その文字をskipした場合に一致しているかを見る。
        int ok = 0;
        int ng = d;
        while (ng - ok > 1) {
            int x = (ok + ng) / 2;
            if (get(l, l+x) == get(r, r+x)) {
                ok = x;
            } else {
                ng = x;
            }
        }
        return get(l+ok+1, l+d) == get(r+ok+1, r+d);
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S;
    cin >> S;

    RollingHash<> rHash(S);

    int Q;
    cin >> Q;

    REP(i, Q){
        int l, r, t;
        cin >> l >> r >> t;
        l--;

        // S[l..r)が周期t　-> S[l..r-t) = S[l+t..r)
        int d = r - t - l;
        l = l;
        r = l + t;

        // そもそも一致していればOK
        if (rHash.is_same(l, r, d)){
            print("Yes");
            continue;
        }

        // 少なくともどこまで一致しているかを見る。
        // ⇛　LCP (最長接頭辞）を求める一般的な操作らしい。TODO ライブラリとしてもっとこ
        int ok = 0;
        int ng = d;
        while (ng - ok > 1) {
            int x = (ok + ng) / 2;
            if (rHash.get(l, l+x) == rHash.get(r, r+x)) {
                ok = x;
            } else {
                ng = x;
            }
        }

        // 一致していない文字をどちらかに合わせる。
        int idx = ok;
        if (rHash.get_changed_one_char(l, l+d, l+idx, S[r+idx]) == rHash.get_changed_one_char(r, r+d, l+idx, S[r+idx]) ||
            rHash.get_changed_one_char(l, l+d, r+idx, S[l+idx]) == rHash.get_changed_one_char(r, r+d, r+idx, S[l+idx])){
            print("Yes");
            continue;
        }

        print("No");

    }



    return 0;
}
