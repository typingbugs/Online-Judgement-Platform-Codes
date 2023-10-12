for _ in range(int(input())):
    a = int(input())
    l = 2
    r = 1414213563
    while l < r:
        mid = l + (r - l) // 2
        if mid * (mid - 1) <= a * 2:
            l = mid + 1
        else:
            r = mid
    l -= 1
    print(a - (l - 1) * l // 2 + l)
