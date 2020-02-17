// aribon4-7_a
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
    using hash_type = ll;
//    using hash_type = pair<T,T>;
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
//        T t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return t1;
//        return make_pair(t1, t2);
    }
};


//random_device rd;
mt19937 mt(1);

//unordered_map<RollingHash<>::hash_type, ll> word_hash[201];
RollingHash<>::hash_type word_hash[5001];
ll len[5001];
RollingHash<>::hash_type S_hash[200001][201];


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S;
    cin >> S;
    int M;
    cin >> M;
    vector<string> P(M);
    REP(i, M) cin >> P[i];
    vector<ll> W(M);
    REP(i, M) cin >> W[i];

//    S = "";
//    REP(i, 200000){
//        S += "abcdefghijklmnopqrstuvwxyz"[mt() % 26];
//    }
//    M = 5000;
//    P.resize(M);
//    W.resize(M);
//    REP(i, M){
//        int sz = (mt() % 200) + 1;
//        REP(j, sz){
//            P[i] += "abcdefghijklmnopqrstuvwxyz"[mt() % 26];
//        }
//        W[i] = mt() % 10000;
//    }

//    auto s = chrono::system_clock::now();

    REP (i, M) {
        int sz = (int) P[i].size();
        auto hash = RollingHash<>(P[i]).get(0, sz);
        word_hash[i] = hash;
        len[i] = sz;
//        if (W[i] > word_hash[sz][hash]){
//            word_hash[sz][hash] = W[i];
//        }
    }

    RollingHash<> rHash(S);
    int s_len = S.size();
    REP(i, 200001) REP(sz, 201){
        if (i + sz > s_len) continue;
        S_hash[i][sz] = rHash.get(i, i+sz);
    }

    vector<ll> dp(s_len + 1);
    REP (i, s_len) {
        dp[i+1] = max(dp[i], dp[i+1]);
//        REPN(sz, 1, 201){
//            if (i + sz > S.size()) break;
//
//            auto tmp = S_hash[i][sz];
//            auto tmp = rHash.get(i, i+sz);
//            auto score = word_hash[sz][tmp];
//            if (score > 0){
//                dp[i+sz] = max(dp[i+sz], dp[i] + score);
//            }
//        }
        REP(j, M){
//            int sz = P[j].size();
            int sz = len[j];
            if (i + sz > s_len) continue;
//            if (rHash.get(i, i+sz) == word_hash[j]){
            if (S_hash[i][sz] == word_hash[j]){
                dp[i+sz] = max(dp[i+sz], dp[i] + W[j]);
            }
        }
    }
//    print(static_cast<double>(chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - s).count() / 1000.0));
    print(dp[S.size()]);






    return 0;
}
