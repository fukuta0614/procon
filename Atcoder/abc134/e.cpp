// abc134_e
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

int solve_wrong(int N, vector<int>& A){
    multiset<int> lis;
    REP(i, N){
        int a = -A[i];
        auto it = lis.upper_bound(a);
        if (it == lis.end()){
            lis.insert(a);
        } else {
            lis.erase(it);
            lis.insert(a);
        }
    }
    return lis.size();
}


int solve(int N, vector<int>& A){
    vector<int> lis;
    REP(i, N){
        int a = -A[i];
        auto it = upper_bound(ALL(lis), a);
        if (it == lis.end()){
            lis.emplace_back(a);
        } else {
            *it = a;
        }
    }
    return lis.size();
}

random_device rd;
mt19937 mt(rd());

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    N = 10;
    A = {1, 10, 9, 9, 5, 10, 2, 9, 9, 3};

    int ans1 = solve(N, A);
    print(ans1);

    return 0;
}
