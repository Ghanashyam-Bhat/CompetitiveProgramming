trials = int(input())
for trial in range(trials):
    x = int(input())
    l = list(map(int,list(input().split())))
    s = set(l)
    if x%2 ==0:
        print(len(s))
    else:
        print(len(s)-1)
    