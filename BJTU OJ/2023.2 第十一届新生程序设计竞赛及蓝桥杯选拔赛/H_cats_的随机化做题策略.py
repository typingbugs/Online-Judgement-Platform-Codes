n = input()
ans = 0
inp = input().split()
for _ in inp:
    ans += 100 / eval(_) * 20 - 20
print(ans)
