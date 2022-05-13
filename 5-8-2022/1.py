trials = int(input())
for trial in range(trials):
    l = tuple(map(int,list(input().split())))
    a,b,c,x,y = tuple(l)
    x -= a
    y -= b 
    if (x<=0 and y <=0) :
        print("YES")
    else:
        if(x>0 and y>0):
            c-=x 
            c-= y 
        elif (x>0):
            c-=x 
        else:
            c-= y 
        if (c>=0):
                print("YES")
        else:
            print("NO")