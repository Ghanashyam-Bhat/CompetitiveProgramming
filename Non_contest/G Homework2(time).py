trials = int(input())
for trial in range(trials):
    a,b,c,m = input().split()
    a,b,c,m = int(a),int(b),int(c),int(m)
    x = 1
    if m <1 and b+c >= a-1 and a+c >= b-1 and a+b>= c-1 :
        print("YES")
    elif m>=1:
        l = [a,b,c]
        while(m):
            l.sort(reverse=True)
            if l[0] <2:
                print("NO")
                x = 0
                break;
            l[0] -= 1
            m -= 1
        if m <1 and l[0]+l[1] >= l[2]-1 and l[1]+l[2] >= l[0]-1 and l[0]+l[2] >= l[1]-1 :
            print("YES")
        elif(x):
            print("NO")
    else:
        print("NO")