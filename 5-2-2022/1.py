from cmath import sqrt


trials = int(input())
for trial in range(trials):
    x,y = input().split()
    x,y = int(x),int(y)
    if x>y:
        print(0,0)
    elif x==y:
        print(1,1)
    else:
        if y%x !=0:
            print(0,0)
        else:
            y /= x 
            y = int(y)
            for i in range(y,0,-1):
                c  = 1
                s = i**c
                while s<y:
                    c+=1
                if(s==y):
                    print(c,i)
                    break