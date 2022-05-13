trials = int(input())
for trial in range(trials):
    s = len(input())
    t = input()
    x = len(t)
    y = t.count('a')
    if 'a' in t and x!=1 :
        print(-1)
    elif 'a' in t and  x==1 :
        print(1)
    else:
        print(2**s)