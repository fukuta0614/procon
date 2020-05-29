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
    REP(i, D) {cin >> C[i]; C[i]--;}

    ll mx_c = 1e5;
    vector<vector<ll>> cycle(mx_c);
    REP(i, D) cycle[C[i]].emplace_back(i);

    vector<ll> cycle_cnt(mx_c); // 好物がCiの人が1周で食堂に行く回数
    vector<vector<ll>> cycle_cnt_vec(mx_c); // 好物がCiの人が1周で食堂に行く回数の累積和
    vector<ll> cycle_like_num(mx_c); // 1周にある好物料理の数
    REP(i, mx_c){
        cycle_like_num[i] = cycle[i].size();
        if (cycle_like_num[i] == 0) continue;

        // ２周分もっとく。
        REP(j, cycle_like_num[i]){
            cycle[i].emplace_back(cycle[i][j] + D);
        }

        // 2周分
        ll cnt = 1;
        cycle_cnt_vec[i].emplace_back(cnt);
        REP(j, 2 * cycle_like_num[i]-1){
            ll x = cycle[i][j+1] - cycle[i][j];
            cnt += (x-1) / L + 1;
            cycle_cnt_vec[i].emplace_back(cnt);
        }
        cycle_cnt[i] = cycle_cnt_vec[i][cycle_like_num[i]]-1;
    }

    REP(q, N){
        ll K, F, T;
        cin >> K >> F >> T;
        K--; F--;

        // 好物が周期になければ
        if (cycle_like_num[K] == 0){ print(0); continue; }

        // 一番近い好物までいく
        int idx = distance(cycle[K].begin(), lower_bound(ALL(cycle[K]), F));
        if (C[F] != K){
            ll x = cycle[K][idx] - F;
            T -= (x-1) / L + 1;
        }

        // その前にTが終わったら、
        if (T <= 0){ print(0); continue; }

        // ループ
        ll ans = cycle_like_num[K] * (T / cycle_cnt[K]);
        T %= cycle_cnt[K];

        // あまり
//        auto it = lower_bound(ALL(cycle_cnt_vec[K]), T + cycle_cnt_vec[K][idx]);
//        ll cnt = distance(cycle_cnt_vec[K].begin(), it) - idx;
//        ans += cnt;

        auto it = upper_bound(next(cycle_cnt_vec[K].begin(), idx),
                              next(cycle_cnt_vec[K].begin(), idx + cycle_like_num[K]+1),
                              T + ((idx>0) ? cycle_cnt_vec[K][idx-1] : 0));
        ll cnt = distance(cycle_cnt_vec[K].begin(), it) - idx;
        ans += cnt;

        print(ans);

    }

    return 0;
}
