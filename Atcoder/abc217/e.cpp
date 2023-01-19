// abc217_e
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
using P = pair<int, int>;

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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int Q;
    cin >> Q;

    priority_queue<int, vector<int>, greater<>> pq;
    deque<int> rest;

    REP(i, Q){
        int c;
        cin >> c;

//        auto tmp = pq;
//        vector<int> tmp2;
//        while (not tmp.empty()) {tmp2.emplace_back(tmp.top()); tmp.pop();}
//        print(tmp2, rest);

        if (c == 1){
            int x;
            cin >> x;

            rest.emplace_back(x);

        } else if (c == 2){

            if (not pq.empty()){
                print(pq.top());
                pq.pop();
            } else {
                print(rest.front());
                rest.pop_front();
            }

        } else {
            while (not rest.empty()) {
                pq.emplace(rest.front());
                rest.pop_front();
            }
        }

    }

    return 0;
}
