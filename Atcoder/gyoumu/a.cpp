// gyoumu_a
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

#define PRINT_DEBUG

random_device rd;
mt19937 mt(10);


vector<int> make_input(){
    // とりあえず
    int unit_num = 24;
    int unit_num_each_max = 6;
    int unit_kind_num = 10;

    vector<int> input;
    auto tmp = unit_num;
    REP(i, unit_kind_num){
        int num = mt() % min(unit_num_each_max, tmp);
        if (i == unit_kind_num - 1){
            num = tmp;
        }
        tmp -= num;
        input.emplace_back(num);
    }
    return input;
}

struct CombinationGenerator {
    ll sup, ret;
    bool first;
    CombinationGenerator(int n, int k): sup(1ll<<n), ret((1ll<<k)-1) {first = true;}
    ll operator()(){
        if (first) {first = false; return ret;}
        if (ret == 0) return -1;
        ll x = ret & -ret, y = ret + x;
        ret = ((ret & ~y) / x >> 1) | y;
        return ret < sup ? ret : -1;
    }
};

struct Solver{

    vector<pair<string, int>> units = {{"TH",   12},
                                       {"HA",   33},
                                       {"HV",   30},
                                       {"ST",   30},
                                       {"CA",   38},
                                       {"FV",   40},
                                       {"CAN",  16},
                                       {"EN0",  16},
                                       {"EN6",  76},
                                       {"EN12", 136}};
    int unit_kind_num;

    int unit_num;

    vector<int> cap;

    const int unit_num_per_master = 8;

    vector<int> input;

    Solver(vector<int> input_): input(input_){
        unit_kind_num = units.size();

        REP(i, 8) cap.emplace_back(200);

        unit_num = 0;
        for (auto n: input) unit_num += n;

        test1();


    }

    bool is_valid(ll key, int cap){

        vector<int> combination;
        REP(i, unit_num_per_master){
            combination.emplace_back(key % 10);
            key /= 10;
        }

        // 条件1 最大容量 を超えない
        int sm = 0;
        REP(i, unit_num_per_master){
            int unit_idx = combination[i];
            sm += units[unit_idx].second;
        }
        if (sm > cap) return false;

        // 条件2~ 一旦無視。


        return true;

    }

    map<ll, bool> ok_10;
    map<ll, bool> ok_20;
    void rec_loop(int prev, ll key, int loop_depth){

        if (loop_depth == 0){
            ok_10[key] = is_valid(key, 10);
            ok_20[key] = is_valid(key, 20);
            return;
        }

        REPN(i, prev, 10){
            key = 10 * key + i;
            rec_loop(i, key, loop_depth-1);
        }
    }

    void test1(){
        rec_loop(0, 0, unit_num_per_master);
    }

    void func1(vector<int> &sorted_input,
               vector<int> &costs,
               vector<int> &cost_list) {
        vector<int> indices(input.size());
        iota(ALL(indices), 0);
        sort(ALL(indices), [&](int i, int j) {
            return units[i].second > units[j].second;
        });

        for (auto idx: indices) {
            costs.emplace_back(units[idx].second);
            sorted_input.emplace_back(input[idx]);

            REP(n, input[idx]) cost_list.emplace_back(units[idx].second);
        }


    }

    // 消費量を降順でソートして、一番空きが多いやつに詰めていく
    int solve1(){

        vector<int> sorted_input;
        vector<int> costs;
        vector<int> cost_list;
        func1(sorted_input, costs, cost_list);

        // ここから

#ifdef PRINT_DEBUG
        print(input);
        print(cost_list);
        print("unitnum:", cost_list.size());
        int sm = accumulate(ALL(cost_list), 0);
        print("sum:", sm);
        print("min:", sm / 200 + 1);
#endif

        int ans = -1;
        vector<vector<int>> ret;
        REPN(num, 1, 9 + 1){
            ret.assign(num, vector<int>());

            vector<int> cap(num, 200);
            bool possible = true;
            REP(i, unit_kind_num) REP(n, sorted_input[i]){
                int idx = max_element(ALL(cap)) - cap.begin();
                cap[idx] -= costs[i];
                ret[idx].emplace_back(costs[i]);
                if (ret[idx].size() == 8) cap[idx] = 0;

                if (cap[idx] < 0) {
                    possible = false;
                    break;
                }
            }

            if (possible || num == 9) {
                if (possible) ans = num;

#ifdef PRINT_DEBUG
                int cnt = 0;
                REP(i, num) {
                    cout << "リモート " << i << " には " << ret[i].size() << " 個 計 ";
                    cout << accumulate(ALL(ret[i]), 0) << " ";
                    cout << "[ ";
                    for (auto c: ret[i]){
                        cout << setw(3) << c << ", ";
                    }
                    cout << "]" << endl;
                    cnt += ret[i].size();
                }
                print(cnt);
#endif
                break;
            }
        }



        return ans;
    }



    // †全探索†
    void solve_bruteforce(){

        vector<int> sorted_input;
        vector<int> costs;
        vector<int> cost_list;
        func1(sorted_input, costs, cost_list);

        int ans = 0;
        REPN(num, 1, 9 + 1){

            vector<int> cap(num, 200);
            bool possible = true;
            for (auto c: cost_list){

            }

            if (possible) {
                ans = num;
                break;
            }
        }

    }

};





int main() {
#ifdef LOCAL
    ifstream in("../arg.txt");
    cin.rdbuf(in.rdbuf());
#endif

    // ランダム入力
//    vector<int> input = make_input();

    REP(i, 0){
        vector<int> input(10);
        REP(k, 10) cin >> input[k];

        int ans;
        cin >> ans;

        auto solver = Solver(input);
        int ret = solver.solve1();
        print(input);
        if (ans == ret){
            print("pulp ans =", ans, " my ans =", ret, "same!!!");
        } else if (ans < ret){
            print("pulp ans =", ans, " my ans =", ret, "my ans is wrong");
        } else{
            if (ret == -1){
                print("pulp ans =", ans, " my ans =", ret, "my ans is too bad");
            } else{
                print("pulp ans =", ans, " my ans =", ret, "my ans is better");
            }
        }
    }

    vector<int> input{17, 4, 6, 3, 0, 7, 0, 2, 4, 4};
    auto solver = Solver(input);
    int ret = solver.solve1();
    print(ret);
    return 0;
}


