// abc141_e
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


bool is_valid(int len, int N, RollingHash<>& rHash){

    REP(i, N-2*len+1) REPN(j, i+len, N-len+1){
        if (rHash.get(i, i+len) == rHash.get(j, j+len)){
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    string S;
    cin >> S;

    auto rHash = RollingHash<>(S);

    int ok = 0;
    int ng = N;
    while (ng - ok > 1){

        int len = (ok + ng) / 2;

        if (is_valid(len, N, rHash)){
            ok = len;
        } else {
            ng = len;
        }
    }
    print(ok);

    return 0;
}
