// arc071_e
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

int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string S, T;
    cin >> S >> T;
    int q;
    cin >> q;

    vector<int> cumsum_s_a(S.size()+1);
    vector<int> cumsum_s_b(S.size()+1);
    REP(i, S.size()){
        cumsum_s_a[i+1] = cumsum_s_a[i] + (S[i] == 'A');
        cumsum_s_b[i+1] = cumsum_s_b[i] + (S[i] == 'B');
    }

    vector<int> cumsum_t_a(T.size()+1);
    vector<int> cumsum_t_b(T.size()+1);
    REP(i, T.size()){
        cumsum_t_a[i+1] = cumsum_t_a[i] + (T[i] == 'A');
        cumsum_t_b[i+1] = cumsum_t_b[i] + (T[i] == 'B');
    }

    while (q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;

//        print(S.substr(a, b-a+1), T.substr(c, d-c+1));

        int s_a = cumsum_s_a[b+1] - cumsum_s_a[a];
        int s_b = cumsum_s_b[b+1] - cumsum_s_b[a];

        int t_a = cumsum_t_a[d+1] - cumsum_t_a[c];
        int t_b = cumsum_t_b[d+1] - cumsum_t_b[c];

        int x = s_a + 2 * s_b;
        int y = t_a + 2 * t_b;

        if (x % 3 == y % 3){
            print("YES");
        } else {
            print("NO");
        }

    }


    return 0;
}
