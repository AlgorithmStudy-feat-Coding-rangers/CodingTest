plusExpressions = input().split("-")

sums = [
    sum(list(map(int, plusExpression.split("+")))) for plusExpression in plusExpressions
]
min = sums[0] - sum(sums[1:])

print(min)