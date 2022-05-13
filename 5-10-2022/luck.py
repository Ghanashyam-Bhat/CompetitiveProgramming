trials = int(input())
for trial in range(trials):
    s = list(map(int,list(input())))
    if sum(s[:3])==sum(s[3:]):
        print("YES")
    else:
        print("NO")