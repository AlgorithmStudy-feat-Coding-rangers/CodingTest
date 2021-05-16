n = int(input())
xys = [tuple(map(int, input().split())) for i in range(n)]
xys.sort(key=lambda xy: (xy[0], xy[1]))

for xy in xys:
    print(xy[0], xy[1])
