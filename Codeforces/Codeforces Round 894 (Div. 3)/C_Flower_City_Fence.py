for _ in range(int(input())):
    n = int(input())
    p = list(map(int, input().split(" ")))
    if n != p[0]:
        print("NO")
        continue
    flag = True
    for index in range(n):
        if p[p[-1 - index] - 1] < p[0] - index:
            flag = False
            break
    print("YES" if flag else "NO")
