points = [
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 
    [1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
    [1, 2, 3, 3, 3, 3, 3, 3, 2, 1], 
    [1, 2, 3, 4, 4, 4, 4, 3, 2, 1], 
    [1, 2, 3, 4, 5, 5, 4, 3, 2, 1], 
    [1, 2, 3, 4, 5, 5, 4, 3, 2, 1], 
    [1, 2, 3, 4, 4, 4, 4, 3, 2, 1], 
    [1, 2, 3, 3, 3, 3, 3, 3, 2, 1], 
    [1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 
          ]

t = int(input())
while t != 0:
    t -= 1
    ans = 0
    for i in range(10):
        a = input()
        for j in range(10):
            if a[j] == 'X':
                ans += points[i][j]
    print(ans)

