// past02_m
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

#define INF (ll)(1e9)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    ll D, L, N;
    cin >> D >> L >> N;
    vector<ll> C(D);
    ll mx_c = 1e5;
    REP(i, D) cin >> C[i];

    vector<vector<int>> cycle(mx_c+1);
    REP(i, D){
        cycle[C[i]].emplace_back(i);
    }

//    print(C);
//    print(cycle);

    vector<ll> cycle_cnt(mx_c+1); // 好物がCiの人が1周で食堂に行く回数
    vector<vector<ll>> cycle_cnt_vec(mx_c+1); // 好物がCiの人が1周で食堂に行く回数の累積和
    vector<ll> cycle_like_num(mx_c+1); // 1周にある好物料理の数
    REP(i, mx_c+1){
        cycle_like_num[i] = cycle[i].size();
        if (cycle_like_num[i] == 0) continue;

        // にぶたん用に２周分もっとく。
        REP(j, cycle_like_num[i]){
            cycle[i].emplace_back(cycle[i][j] + D);
        }

        ll cnt = 0;
        REP(j, cycle_like_num[i]){
            ll x = cycle[i][j+1] - cycle[i][j];
            cnt += (x-1) / L + 1;
            cycle_cnt_vec[i].emplace_back(cnt);
        }
        cycle_cnt[i] = cnt;

        // ******** ココだった！！！！*******
        // 2週分しかもってなくて、最初に見つける好物が2週目だと、3週目の先頭まで見に行く必要がある。それでばぐってた
//        // にぶたん用に2周分もっとく。
//        REP(j, cycle_like_num[i]){
//            cycle_cnt_vec[i].emplace_back(cycle_cnt[i] + cycle_cnt_vec[i][j]);
//        }
        // にぶたん用に3周分もっとく。
        REP(j, 2*cycle_like_num[i]){
            cycle_cnt_vec[i].emplace_back(cycle_cnt[i] + cycle_cnt_vec[i][j]);
        }

//        print(i);
//        print(cycle[i]);
//        print(cycle_like_num[i]);
//        print(cycle_cnt[i]);
//        print(cycle_cnt_vec[i]);
    }

    REP(q, N){
        ll K, F, T;
        cin >> K >> F >> T;
        F--;

//        print("start", q);

        ll ans = 0;

        // 好物が周期になければ
        if (cycle_like_num[K] == 0){
            print(ans);
            continue;
        }

        // 一番近い好物の直前までいく
        // 最初が好物でなかったら、それまでの食堂回数分減らす
//        print(K, F, T);
//        print(cycle[K]);

        int idx = distance(cycle[K].begin(), lower_bound(ALL(cycle[K]), F));
        if (C[F] != K){
            ll x = cycle[K][idx] - F;
            T -= (x-1) / L + 1;
        }

        // その前にTが終わったら、
        if (T <= 0){
            print(ans);
            continue;
        }

        // 好物を食べる。
        T--;
        ans++;

//        print(idx, cycle[K][idx], T, ans);

//        print(cycle_like_num[K]);
//        print(cycle_cnt[K]);

        // ループ
        ans += cycle_like_num[K] * (T / cycle_cnt[K]);
        T %= cycle_cnt[K];

//        print(T, ans);
//
//        print(cycle_cnt_vec[K]);

        // あまり
        auto it = upper_bound(next(cycle_cnt_vec[K].begin(), idx),
                              next(cycle_cnt_vec[K].begin(), idx + cycle_like_num[K]+1),
                              T + ((idx>0) ? cycle_cnt_vec[K][idx-1] : 0));

        int cnt = distance(cycle_cnt_vec[K].begin(), it) - idx;
        ans += cnt;

        print(ans);

    }

    return 0;
}
