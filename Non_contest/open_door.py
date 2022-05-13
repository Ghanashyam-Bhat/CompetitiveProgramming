trials = int(input())
for trial in range(trials):
    s = list(input())
    r,g,b = 0,0,0
    for i in s:
        if i=='r':
            r = 1
        elif i=='g':
            g = 1
        elif i == 'b':
            b =1
        elif (i=="R" and r==1) or (i=="G" and g==1) or (i=="B" and b==1):
            continue
        else:
            #print(i)
            print("NO")
            break
    else:
        print("YES")