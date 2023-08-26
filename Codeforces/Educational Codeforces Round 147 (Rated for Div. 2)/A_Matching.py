def solve():
    s = input()
    if s[0] == '0':
        print(0)
        return

    times = s.count('?') - 1
    if s[0] == '?':
        print('9', end='')
    else:
        print('1',end='')
        times += 1
    print('0' * times)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()