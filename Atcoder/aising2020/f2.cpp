#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int64_t power_mod(int64_t num, int64_t power){
    int64_t prod = 1;
    num %= MOD;
    while(power > 0){
        if(power&1) prod = prod * num % MOD;
        num = num * num % MOD;
        power >>= 1;
    }
    return prod;
}

int64_t extgcd(int64_t a, int64_t b, int64_t& x, int64_t& y){
    int64_t d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}

int64_t inv_mod(int64_t a){
    int64_t x, y;
    extgcd(a, MOD, x, y);
    return (MOD + x%MOD) % MOD;
}

vector<int64_t> fact, fact_inv;

void create_mod_tables(int num){
    fact.assign(num+1, 1);
    fact_inv.assign(num+1, 1);
    for(int i=1; i<=num; i++) fact[i] = fact[i-1] * i % MOD;
    fact_inv[num] = inv_mod(fact[num]);
    for(int i=num; i>0; i--) fact_inv[i-1] = fact_inv[i] * i % MOD;
}

int64_t comb_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD * fact_inv[k] % MOD;
}

int64_t perm_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD;
}

// P = {P[0], P[1], ..., P[N]}
int64_t LagrangeInterpolation(vector<int64_t> P, int64_t T){
    int N = P.size()-1;
    if(T <= N) return P[T];
    int64_t Qi = 1, QTA = 1;
    for(int i=0; i<=N; i++){
        if(i) mul(Qi, MOD-i);
        mul(QTA, T-i);
    }
    int64_t ans = 0;
    for(int i=0; i<=N; i++){
        add(ans, P[i] * inv_mod(Qi) % MOD * QTA % MOD * inv_mod(T-i));
        mul(Qi, (i+1) * inv_mod(MOD-N+i) % MOD);
    }
    return ans;
}

int64_t calc(int N){
    int64_t ans = 0;
    for(int i=0; 2*i+5<=N; i++) add(ans, comb_mod(i+4, 4) * comb_mod(N-2*i+5, 10));
    return ans;
}

void solve(){
    int N;
    cin >> N;
    if(N < 5){
        cout << 0 << endl;
        return;
    }
    int r = (N-5)%2, n = (N-5)/2;
    vector<int64_t> V(16);
    for(int i=0; i<=15; i++) V[i] = calc(2*i+5+r);
    cout << N << endl;
    for (int j = 0; j <= 15; ++j) {
        cout << V[j] << " ";
    }
    cout << endl;
    int64_t ans = LagrangeInterpolation(V, n);
    cout << ans << endl;
}

int main(){
#ifdef LOCAL
    ifstream in("../arg.txt"); cin.rdbuf(in.rdbuf());
#endif
    create_mod_tables(100);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
