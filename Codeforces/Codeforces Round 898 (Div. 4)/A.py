ans = {'abc', 'acb', 'bac', 'cba'}

t = int(input())
while t != 0:
    t -= 1
    print('YES' if input() in ans else 'NO')
