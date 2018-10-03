A, B, C, K = [int(_) for _ in input().split()]
S, T = [int(_) for _ in input().split()]


ans = S * A + T * B
if S + T >= K:
    ans -= (S+T)*C
print(ans)