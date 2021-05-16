def memo_sum(N):
    for r in range(1, N + 1):
        for c in range(1, r + 2):
            sum[r][c] += max(sum[r - 1][c], sum[r - 1][c - 1])


sum = [[0] * 502 for _ in range(502)]
N = int(input())
for n in range(N):
    numbers = list(map(int, input().split()))
    # out of index 방지를 위해 맨 왼쪽열에 0을 넣어줌. 이를 위해 인덱스를 1부터 시작
    sum[n][1 : len(numbers) + 1] = numbers

memo_sum(N)
print(max(sum[n]))
