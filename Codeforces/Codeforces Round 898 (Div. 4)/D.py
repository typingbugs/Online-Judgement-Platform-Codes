t = int(input())
while t != 0:
    t -= 1
    n, k = list(map(int, input().split()))
    a = input()
    ans = 0
    i = 0
    while i < n:
        if a[i] == 'B':
            ans += 1
            i += k
        else:
            i += 1
    print(ans)

