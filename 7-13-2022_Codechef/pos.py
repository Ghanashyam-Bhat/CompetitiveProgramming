trials = int(input())
for trial in range(trials):
    n = int(input())
    l = list(map(int,list(input().split())))
    ma = l.index(max(l))
    mi = l.index(min(l))
    if ma<mi:
        c = mi + n - ma -2 
    else:
        c = mi + n - ma -1
    print(c)