def fun(n,r1,r2,x,y,c):
    #print(x,y)
    if x==n-1 and y==1:
        #print("Returning YES")
        return 1
    elif x<n:
        #print("Test")
        if x<n-1 and r1[x+1]=='0' and y==0:
            return fun(n,r1,r2,x+1,y,1)
        if x<n-1 and r2[x+1]=='0' and y==1:
            return fun(n,r1,r2,x+1,y,1)
        elif r2[x]=='0' and y==0 and c!=0:
            return  fun(n,r1,r2,x,y+1,0)
        elif r1[x]=='0' and y==1 and c!=0:
             return fun(n,r1,r2,x,y-1,0)
        elif x<n-1 and r2[x+1]=='0' and y==0:
             return fun(n,r1,r2,x+1,y+1,1)
        elif x<n-1 and r1[x+1]=='0' and y==1:
             return fun(n,r1,r2,x+1,y-1,1)
        else :
            #print("Returning No")
            return 0
    else :
        return 0


trials = int(input())
for trial in range(trials):
    n = int(input())
    r1 = list(input())
    r2 = list(input())
    if fun(n,r1,r2,0,0,0)==1:
        print("YES")
    else :
        print("NO")
