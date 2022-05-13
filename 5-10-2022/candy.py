trials = int(input())
for trial in range(trials):
    x = input()
    s = list(map(int,list(input().split())))
    m = min(s)
    t = 0
    for i in s:
        t += (i-m)
    print(t)