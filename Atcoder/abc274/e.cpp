// abc274_e
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug_util/cxx-prettyprint/prettyprint.hpp"
#include "../../debug_util/rng.hpp"
#include "../../debug_util/timer.hpp"
#endif
using namespace std;

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using P2 = pair<double, int>;

#define REP(i, n) for (int i = 0 ; i < (int)(n) ; ++i)
#define REPN(i, m, n) for (int i = m ; i < (int)(n) ; ++i)
#define REP_REV(i, n) for (int i = (int)(n) - 1 ; i >= 0 ; --i)
#define REPN_REV(i, m, n) for (int i = (int)(n) - 1 ; i >= m ; --i)
#define ALL(x) x.begin(), x.end()

#define INF (ll)(1e15)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int idx=0;idx<(n-1);idx++) cout << (vec)[idx] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << "\n";}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

string to_bin(int n){ std::stringstream ss; ss << std::bitset<8>(n); return ss.str(); }

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N, M;
    cin >> N >> M;
    int num = N + M + 1; // 原点+町N+宝箱M

    vector<P> pos(num);

    pos[0] = {0, 0};
    REP(i, N) {
        int x, y;
        cin >> x >> y;
        pos[i+1] = {x, y};
    }
    REP(i, M){
        int x, y;
        cin >> x >> y;
        pos[i+N+1] = {x, y};
    }

    int mx = (1 << num) * num;
    vector<double> cost_table(mx, INF);
    cost_table[0] = 0;

    priority_queue<P2, vector<P2>, greater<>> pq;
    pq.emplace(0, 0);

    auto calc_dist = [](P a, P b){
        ll d1 = (a.first - b.first) * (a.first - b.first);
        ll d2 = (a.second - b.second) * (a.second - b.second);
        return sqrt(d1 + d2);
    };

//    print(pos);

    double ans = INF;
    while (!pq.empty()){

        P2 p = pq.top(); pq.pop();

        double cost = p.first;

        int node = p.second;
        int visit = node / num;
        int idx = node % num;

        int all_visit = ((1 << N) - 1) << 1;
        if (((visit & all_visit) == all_visit) && idx == 0){
            ans = min(ans, cost);
        }

        int cur_speed = 1;
        REP(i, M){
            if ((visit >> (i+N+1)) & 1) cur_speed *= 2;
        }
//        print(idx, to_bin(visit), cost);

        REP(i, num) {
            if (i == idx) continue;

            double dist = calc_dist(pos[i], pos[idx]);
            double next_cost = cost + dist / cur_speed;

            int next_visit = visit | (1 << i);
            int next_p = num * next_visit + i;

            if (next_cost < cost_table[next_p]){
                cost_table[next_p] = next_cost;
                pq.emplace(next_cost, next_p);
            }
        }
    }

    print(ans);


    return 0;
}
