trials = int(input())
input()
for trial in range(trials):
    l = []
    for i in range(8):
        l.append(list(input()))
    if trial!= trials-1:
        input()
    x = 0
    y = 0
    p = 2
    for k in range(1,8):
        i = l[k]
        if '#' in i and i.count('#')==1:
            p = 1
        elif '#' in i and i.count('#')==2:
            if p==1:
                x = k
                y = l[k-1].index('#')+1
                p = 2
        elif (p==2 or p==0 ) and x!=0 and y!=0:
            print(x,y)
            break