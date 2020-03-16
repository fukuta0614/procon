// panasonic2020_e
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


//// kmp をやるための前計算
//vector<int> makeTable(const string& s) {
//    int n = s.size();
//    vector<int> ret(n+1);
//    ret[0] = -1;
//    int j = -1;
//    for (int i = 0; i < n; i++) {
//        while (j >= 0 && s[i] != s[j]) j = ret[j];
//        ret[i+1] = ++j;
//    }
//    return ret;
//}
//
//// str の中に word とマッチする場所のリストを返す
//// ret のそれぞれの要素 el は, 「str[el] からの文字列が word と一致する」ことを示す
//vector<int> kmp(const string& str, const string& word) {
//    vector<int> table = makeTable(word), ret;
//    int m = 0, i = 0, n = str.size();
//    while (m+i < n) {
//        if (word[i] == str[m+i]) {
//            if (++i == (int)(word.size())) {
//                ret.push_back(m);
//                m = m+i-table[i];
//                i = table[i];
//            }
//        } else {
//            m = m+i-table[i];
//            if (i > 0) i = table[i];
//        }
//    }
//    return ret;
//}



// kmp をやるための前計算
vector<int> makeTable(const string& s) {
    int n = s.size();
    vector<int> ret(n+1);
    ret[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?'){
            j = i == 0 ? 0 : ret[i-1];
        } else{
            while (j >= 0 && s[i] != s[j]) j = ret[j];
        }
        ret[i+1] = ++j;
    }
    return ret;
}

// str の中に word とマッチする場所のリストを返す
// ret のそれぞれの要素 el は, 「str[el] からの文字列が word と一致する」ことを示す
vector<int> kmp(const string& str, const string& word) {
    vector<int> table = makeTable(word), ret;
//    print(table);
    int m = 0, i = 0, n = str.size();
    while (m+i < n) {
        if (word[i] == str[m+i] || word[i] == '?' || str[m+i] == '?') {
            i++;
            if (i == (int)(word.size()) || (m+i) == str.size()) {
                ret.push_back(m);
                m = m+i-table[i];
                i = table[i];
            }
        } else {
            m = m+i-table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}



int main() {
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif

    string a, b, c;
    cin >> a >> b >> c;


    auto merge = [](string a, string b, int idx){
        string s;
        REP(i, a.size()){
            if (i < idx){
                s += a[i];
            } else{
                if (a[i] == '?' && b[i-idx] == '?'){
                    s += '?';
                } else if (a[i] == '?'){
                    s += b[i-idx];
                } else {
                    s += a[i];
                }
            }
        }
        if (idx + b.size() > a.size()){
            s += b.substr(a.size()-idx, idx + b.size() - a.size());
        }
        return s;
    };

    auto func = [&merge](string a, string b, string c){

        vector<int> ret = kmp(a, b);
        string s;
        if (ret.size() > 0){
            int idx = ret[0];
            s = merge(a, b, idx);
        } else {
            s = a + b;
        }

        ret = kmp(s, c);
        string t;
        if (ret.size() > 0){
            int idx = ret[0];
            t = merge(s, c, idx);
        } else {
            t = s + c;
        }
//        print(t);
        return (int)t.size();
    };

    int ans = INF;
    ans = min(ans, func(a, b, c));
    ans = min(ans, func(a, c, b));
    ans = min(ans, func(b, a, c));
    ans = min(ans, func(b, c, a));
    ans = min(ans, func(c, a, b));
    ans = min(ans, func(c, b, a));

    print(ans);


    return 0;
}
