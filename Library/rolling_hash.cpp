//
// Created by 福田圭佑 on 2020/01/13.
//

template <typename T=long long, T base1=1009, T base2=1007, T mod1=1000000007, T mod2=1000000009>
struct RollingHash {
    using hash_type = pair<T,T>;
    vector<T> hash1, hash2;
    vector<T> pow1, pow2;

    explicit RollingHash(const string &s) {
        auto n = (int)s.size();

        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1,1);
        pow2.assign(n+1,1);

        for(int i=0;i<n;i++) {
            hash1[i+1] = (hash1[i] * base1 + s[i]) % mod1;
            hash2[i+1] = (hash2[i] * base2 + s[i]) % mod2;
            pow1[i+1] = pow1[i] * base1 % mod1;
            pow2[i+1] = pow2[i] * base2 % mod2;
        }
    }

    hash_type get(int l,int r) {
        T t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        T t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return make_pair(t1, t2);
    }

    // ハッシュ値がh1の文字列の末尾に、長さh2_lenでハッシュ値がh2をくっつけた文字列のハッシュ値
    hash_type concat(hash_type h1, hash_type h2, int h2_len) {
        assert(h2_len < pow1.size());
        T t1 = (h1.first * pow1[h2_len] + h2.first) % mod1;
        T t2 = (h2.second * pow2[h2_len] + h2.second) % mod2;
        return make_pair(t1, t2);
    }
};