for _ in range(int(input())):
    s = input().split(" ")
    x, y = int(s[0]), int(s[1])
    vika = ["v", "i", "k", "a"]
    s = ""
    for __ in range(x):
        s += input()
    index = int(0)
    for j in range(y):
        for i in range(x):
            if index < 4 and s[y * i + j] == vika[index]:
                index += 1
                break
    if index == 4:
        print("YES")
    else:
        print("NO")
