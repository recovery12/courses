
n, x = map(int, input().split())
candies = list(map(int, input().split()))

friends = 0
for candy in candies:
    if x < candy:
        friends = friends + 1

print(friends)
