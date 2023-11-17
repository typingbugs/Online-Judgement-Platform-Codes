ans = ["Second", "First", "First"]
t = int(input())
while t > 0:
    t -= 1
    num = int(input())
    print(ans[num % 3])
