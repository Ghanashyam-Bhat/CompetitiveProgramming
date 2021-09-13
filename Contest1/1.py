trials = int(input())
for trial in range(trials):
    x = int(input())
    a = list(input().split())
    b = list(map(lambda x:int(x),a))
    c = 0
    for i in b:
        c |=i
    print(c)