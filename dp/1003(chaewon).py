def fibo(memo, n):
    memo[0] = (1, 0)
    memo[1] = (0, 1)

    for i in range(2, n + 1):
        memo[i] = (memo[i - 1][0] + memo[i - 2][0], memo[i - 1][1] + memo[i - 2][1])

    return memo[n]


T = int(input())
for t in range(T):
    n = int(input())
    memo = [(0, 0) for i in range(42)]
    cnt = fibo(memo, n)
    print(f"{cnt[0]} {cnt[1]}")
