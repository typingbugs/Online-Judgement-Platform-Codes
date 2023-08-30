for t in range(int(input())):
    l = int(input())
    arr = list(map(int, input().split()))
    ans = l - 1
    idx = [-1] * l
    for i in range(l):
        idx[arr[i] - 1] = i
    for i in range(l - 1):
        if idx[i] < idx[i + 1]:
            ans -= 1
    print(ans)