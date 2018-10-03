import heapq

N = int(input())
cost_f, cost_b = [int(_) for _ in input().split()]
initial_states = [1 if s == "s" else 0 for s in list(input())]
initial_visited = [0] * N
initial_visited[N - 1] = 1
initial_history = [N - 1]


def hash_func(pos, visited, states):
    return pos, ''.join([str(x) for x in visited]), ''.join([str(x) for x in states])


def main():
    q = [(0, N - 1, initial_visited, initial_states[:])]
    k = hash_func(N - 1, initial_visited, initial_states)
    dp_hash = {k: (0, [N - 1])}

    while len(q) > 0:
        cost, current_pos, visited, states = heapq.heappop(q)

        key = hash_func(current_pos, visited, states)
        prev_cost, prev_history = dp_hash[key]
        if prev_cost < cost:
            continue

        for pos in range(N):

            if pos == current_pos:  # can't move to current pos
                continue

            if states[pos] == 0:  # if dangerous
                continue

            if pos == N - 1 and sum(visited) == N:  # finish
                # final_cost = cost + cost_f
                # print(final_cost)
                prev_history.append(N - 1)
                for x in prev_history:
                    print(x+1, end=' ')
                print()
                return

            next_states = [1 - states[i] if i > pos else states[i] for i in range(N)]
            next_cost = cost + (cost_f if pos > current_pos else cost_b)
            next_visited = visited[:]
            next_visited[pos] = 1
            next_history = prev_history[:]
            next_history.append(pos)

            next_key = hash_func(pos, next_visited, next_states)
            if next_key in dp_hash:
                if next_cost < dp_hash[next_key][0]:
                    dp_hash[next_key] = (next_cost, next_history)
                    heapq.heappush(q, (next_cost, pos, next_visited, next_states))
            else:
                dp_hash[next_key] = (next_cost, next_history)
                heapq.heappush(q, (next_cost, pos, next_visited, next_states))


if __name__ == '__main__':
    main()
