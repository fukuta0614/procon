// abc119_d
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) cout << #x << ": " << (x) << endl
#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define all(x) x.begin(), x.end()
#define INF (1ll << 40)
#define MOD (1000000007)
#define print(arr, n) REP(i, n) cout << arr[i] << " ";

struct PreMain {PreMain(){std::cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain;

vector<ll> s, t;

int main() {
#ifdef LOCAL
    std::ifstream in("../arg.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int A, B, Q;
    cin >> A >> B >> Q;
    ll tmp;
    s.emplace_back(-INF);
    t.emplace_back(-INF);
    REP(i, A) {cin >> tmp; s.emplace_back(tmp);}
    REP(i, B) {cin >> tmp; t.emplace_back(tmp);}
    s.emplace_back(INF);
    t.emplace_back(INF);
    sort(all(s)); sort(all(t));

    ll x;
    ll ans;

    REP(i, Q) {
        cin >> x;

        auto s_it = upper_bound(all(s), x);
        auto t_it = upper_bound(all(t), x);

        ll inf1 = *prev(s_it);
        ll sup1 = *s_it;
        ll inf2 = *prev(t_it);
        ll sup2 = *t_it;

        ans = INF;
        ans = min(ans, x - min(inf1, inf2));
        ans = min(ans, max(sup1, sup2) - x);

        ans = min(ans, 2 * (x - inf1) + 1 * (sup2 - x));
        ans = min(ans, 1 * (x - inf1) + 2 * (sup2 - x));

        ans = min(ans, 2 * (x - inf2) + 1 * (sup1 - x));
        ans = min(ans, 1 * (x - inf2) + 2 * (sup1 - x));

        ans = min(ans, 2 * (x - inf1) + 1 * (sup2 - x));
        ans = min(ans, 1 * (x - inf1) + 2 * (sup2 - x));

        cout << ans << endl;
    }

//    //ソートする必要があるのじゃ…
//    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};
//    vector<int> b = {0, 1, 2, 3, 4, 5, 19, 20};
//
//    for (auto x: b){
//        auto it = lower_bound(all(a), x);
//        auto it2 = upper_bound(all(a), x);
//        cout << x << " Iter1 = " << *it << " " << it - a.begin(); //Iter1 = 4
//        cout << " Iter2 = " << *it2 << " " << it2 - a.begin() << endl; //Iter1 = 4
//        if (it == a.begin()){
//            cout << "1 same as begin" << endl;
//        }
//
//        if (it == a.end()){
//            cout << "1 same as end" << endl;
//        }
//
//        if (it2 == a.begin()){
//            cout << "2 same as begin" << endl;
//        }
//
//        if (it2 == a.end()){
//            cout << "2 same as end" << endl;
//        }
//
//    }

    return 0;
}


