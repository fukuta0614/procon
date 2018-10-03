N, M = [int(_) for _ in input().split()]
T = [[int(_)-1 for _ in input().split()] for i in range(M)]

adj = [[] for i in range(N)]
for a, b in T:
    adj[a].append(b)
    adj[b].append(a)


for n in range(N):
    ans = []
    for friend in adj[n]:
        for friend2 in adj[friend]:
            if friend2 in adj[n] or friend2 == n or friend2 in ans:
                continue
            ans.append(friend2)

    print(len(ans))
