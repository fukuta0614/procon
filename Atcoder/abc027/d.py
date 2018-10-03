def main1():
    import sys

    S = input()

    memo = dict()
    def dp(n, p):
        if (n, p) in memo:
            return memo[(n, p)]

        if n == -1:
            if p == 0:
                res = 0
            else:
                res = -float('inf')
        else:
            if S[n] == 'M':
                res = max(dp(n - 1, p - 1), dp(n - 1, p + 1))
            elif S[n] == '+':
                res = dp(n - 1, p) + p
            elif S[n] == '-':
                res = dp(n - 1, p) - p

        memo[(n, p)] = res
        return res

    sys.setrecursionlimit(10000)
    print(dp(len(S) - 1, 0))

S = input()

plusminus = 0
x = []
for i in list(range(len(S)))[::-1]:
    if S[i] == '+':
        plusminus += 1
    elif S[i] == '-':
        plusminus -= 1
    else:
        x.append(plusminus)
t = sorted(x)
l = len(t)//2
print(sum(t[l:]) - sum(t[:l]))

