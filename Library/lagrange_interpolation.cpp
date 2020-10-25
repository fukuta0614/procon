//
// Created by 福田圭佑 on 2020/07/13.
//

// O(d)
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

