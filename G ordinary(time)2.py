#By Ghanashyam Bhat ~ the.giga.byte
trials  = int(input())
for trial in range(trials):
    n = int(input())
    x = 0
    for i in range(1,n+1):
        s = set(str(i))
        if len(s)==1:
            x+=1
    print(x)