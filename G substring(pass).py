n = int(input())
for i in range(n):
    s = list(input())
    print(min(s),end=" ")
    s.remove(min(s))
    print("".join(s))