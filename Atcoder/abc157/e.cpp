// abc157_e
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


struct BIT {
    int sz;
    vector<int> tree;

    BIT(int n) {
        sz = n;
        tree.resize(n+1);
    }

    int sum(int i){
        int sm = 0;
        while (i > 0){
            sm += tree[i];
            i -= i & -i;
        }
        return sm;
    }

    int sum(int l, int r){
        return sum(r) - sum(l);
    }

    void add(int i, int x){
        while (i <= sz){
            tree[i] += x;
            i += i & -i;
        }
    }
};


int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    int N;
    cin >> N;
    string S;
    cin >> S;

//    auto st = BIT(N);
//    st.add(1, 1);
//    st.add(2, 2);
//    st.add(3, 4);
//    print(st.sum(1, 3));

    vector<BIT> treelist;
    REP(i, 26){
        treelist.emplace_back(BIT(N));
    }
    REP(i, N){
        char c = S[i];
        treelist[c-'a'].add(i+1, 1);
    }

    int Q;
    cin >> Q;
    REP(q, Q){
        int t;
        cin >> t;
        if (t == 1){
            int i;
            char c;
            cin >> i >> c;
            char origin = S[i-1];
            treelist[origin-'a'].add(i, -1);
            treelist[c-'a'].add(i, 1);
            S[i-1] = c;
        } else {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            REP(c, 26){
                int sm = treelist[c].sum(l-1, r);
                if (sm > 0) {
                    ans++;
                }
            }
            print(ans);
        }
    }

    return 0;
}
