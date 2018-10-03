mod = 10**9+7

H, W, A, B = [int(_) for _ in input().split()]

fact = [1] * (2 * 10**5+1)
for i in range(1, 2*10**5+1):
    fact[i] = i * fact[i-1] % mod

def comb(n, k):
    a = fact[n] % mod
    b = (fact[k] * fact[n-k]) % mod
    b_ = pow(b, mod-2, mod)
    return  (a * b_) % mod

ans = 0
for w in range(B, W):
    ans += comb(H-A-1 + w, w) * comb(A-1 + W-w-1, W-w-1) % mod

print(ans % mod)
