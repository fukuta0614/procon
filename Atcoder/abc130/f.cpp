// abc130_f
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

#define INF ((1ll << 31)-1)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

struct XYD { double x,y; char d; };


enum POSITION{
    POS_L = 0,
    POS_R,
    POS_D,
    POS_U,
    POS_MAX
};

enum DIRECTION{
    DIR_L= 0,
    DIR_R,
    DIR_D,
    DIR_U,
    DIR_MAX
};

double get_area(double t, vector<vector<double>> &minmax) {

    double left = min(min(minmax[POS_L][DIR_L] - t, minmax[POS_L][DIR_R] + t),
                  min(minmax[POS_L][DIR_D], minmax[POS_L][DIR_U]));

    double right = max(max(minmax[POS_R][DIR_L] - t, minmax[POS_R][DIR_R] + t),
                   max(minmax[POS_R][DIR_D], minmax[POS_R][DIR_U]));


    double down = min(min(minmax[POS_D][DIR_D] - t, minmax[POS_D][DIR_U] + t),
                  min(minmax[POS_D][DIR_L], minmax[POS_D][DIR_R]));

    double up = max(max(minmax[POS_U][DIR_D] - t, minmax[POS_U][DIR_U] + t),
                max(minmax[POS_U][DIR_L], minmax[POS_U][DIR_R]));

    return (right - left) * (up - down);
}

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<XYD> input(N);
    REP(i, N) {
        cin >> input[i].x >> input[i].y >> input[i].d;
    }


    vector<vector<double>> minmax;
    minmax.assign(DIR_MAX, vector<double>(DIR_MAX)); // L R D U
    REP(d, DIR_MAX){
        minmax[POS_L][d] = INF;
        minmax[POS_R][d] = -INF;
        minmax[POS_D][d] = INF;
        minmax[POS_U][d] = -INF;
    }

    map<char, int> mp{{'L', DIR_L}, {'R', DIR_R}, {'D', DIR_D}, {'U', DIR_U}};
    REP(i, N) {
        int dir_idx = mp[input[i].d];
        minmax[POS_L][dir_idx] = min(minmax[POS_L][dir_idx], input[i].x);
        minmax[POS_R][dir_idx] = max(minmax[POS_R][dir_idx], input[i].x);
        minmax[POS_D][dir_idx] = min(minmax[POS_D][dir_idx], input[i].y);
        minmax[POS_U][dir_idx] = max(minmax[POS_U][dir_idx], input[i].y);
    }

    vector<double> candidates;

    candidates.emplace_back((minmax[POS_L][DIR_L] - minmax[POS_L][DIR_R]) / 2);
    candidates.emplace_back((minmax[POS_L][DIR_L] - minmax[POS_L][DIR_D]));
    candidates.emplace_back((minmax[POS_L][DIR_L] - minmax[POS_L][DIR_U]));
    candidates.emplace_back((minmax[POS_L][DIR_U] - minmax[POS_L][DIR_R]));
    candidates.emplace_back((minmax[POS_L][DIR_D] - minmax[POS_L][DIR_R]));

    candidates.emplace_back((minmax[POS_R][DIR_L] - minmax[POS_R][DIR_R]) / 2);
    candidates.emplace_back((minmax[POS_R][DIR_L] - minmax[POS_R][DIR_D]));
    candidates.emplace_back((minmax[POS_R][DIR_L] - minmax[POS_R][DIR_U]));
    candidates.emplace_back((minmax[POS_R][DIR_U] - minmax[POS_R][DIR_R]));
    candidates.emplace_back((minmax[POS_R][DIR_D] - minmax[POS_R][DIR_R]));

    candidates.emplace_back((minmax[POS_D][DIR_D] - minmax[POS_D][DIR_U]) / 2);
    candidates.emplace_back((minmax[POS_D][DIR_D] - minmax[POS_D][DIR_L]));
    candidates.emplace_back((minmax[POS_D][DIR_D] - minmax[POS_D][DIR_R]));
    candidates.emplace_back((minmax[POS_D][DIR_L] - minmax[POS_D][DIR_U]));
    candidates.emplace_back((minmax[POS_D][DIR_R] - minmax[POS_D][DIR_U]));

    candidates.emplace_back((minmax[POS_U][DIR_D] - minmax[POS_U][DIR_U]) / 2);
    candidates.emplace_back((minmax[POS_U][DIR_D] - minmax[POS_U][DIR_L]));
    candidates.emplace_back((minmax[POS_U][DIR_D] - minmax[POS_U][DIR_R]));
    candidates.emplace_back((minmax[POS_U][DIR_L] - minmax[POS_U][DIR_U]));
    candidates.emplace_back((minmax[POS_U][DIR_R] - minmax[POS_U][DIR_U]));

    double ans = get_area(0, minmax);
    for (double t: candidates){
        if (t < 0) continue;
        ans = min(ans, get_area(t, minmax));
    }

    print(ans);


    return 0;
}
