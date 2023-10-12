def solve():
    s = input()
    if s == '()':
        print('NO')
        return
    print('YES')
    output = '()' * len(s)
    if s in output:
        output = '(' * len(s) + ')' * len(s)
    print(output)


if __name__ == '__main__':
    for _ in range(int(input())):
        solve()
