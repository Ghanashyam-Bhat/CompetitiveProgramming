trials = int(input())
for trial in range(trials):
    x = int(input())
    s = input()
    l = []
    c = 0
    prev = s[0]
    for i in s:
        if i==prev:
            c+=1
        else:
            l.append((c,prev))
            prev = i 
            c = 1 
    l.append((c,prev))
    c = 0
    che = 1
    for i in l:
        if i[0]%2!=0:
            che = 0
            break
    if che :
        print(0)
    else:
        for i in range(len(l)-1):
            if l[i][0]%2!=0:
                if l[i+1][0]%2 != 0:
                    c+=min(l[i+1][0],l[i][0])

    print(l)