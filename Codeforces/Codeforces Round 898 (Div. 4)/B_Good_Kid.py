t = int(input())
while t != 0:
    t -= 1
    input()
    l = list(map(int, input().split()))
    _min = 9
    for i in l:
        _min = min(_min, i)
    ans = 1
    for i in range(len(l)):
        if l[i] == _min:
            l[i] = _min + 1
            break
    for i in l:
        ans *= i
    print(ans)
    