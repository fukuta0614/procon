// abc196_b
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

vector<string> split_string(const string& s, char c){
    vector<string> res;
    string tmp;
    REP(i, s.size()){
        if (s[i] == c){
            res.emplace_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    res.emplace_back(tmp);
    return res;
}

ll convert_float_string_to_num(const string& s, int digit){

    auto res = split_string(s, '.');
    assert(res.size() <= 2);

    bool neg = res[0][0] == '-';
    ll a = 0;
    REPN(i, neg ? 1 : 0, res[0].size()){
        a = 10 * a + res[0][i] - '0';
    }

    ll b = 0;
    if (res.size() == 2){
        REP(i, digit){
            b = 10 * b + (i < res[1].size() ? res[1][i] - '0': 0);
        }
    }

    ll ret = (ll)pow(10, digit) * a + b;
    return neg ? -ret : ret;
}

ll cin_double_to_ll(int digit){
    string s;
    cin >> s;
    return convert_float_string_to_num(s, digit);
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif



    return 0;
}
