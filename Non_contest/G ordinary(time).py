#By Ghanashyam Bhat ~ the.giga.byte
trials  = int(input())
for trial in range(trials):
    n = int(input())
    x = 0
    if n > 9:
        x += 9
        for i in range(10,n+1):
            l = list(str(i))
            z = l.copy()
            z.reverse()
            if l == z :
                x+=1
    elif x <= 9:
        x += n
    print(x)