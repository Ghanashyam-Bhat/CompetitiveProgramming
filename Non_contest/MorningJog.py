#https://codeforces.com/problemset/problem/1517/B
#Morning Jogging
trials = int(input())
while trials > 0 :
    trials -= 1
    n,m = input().split(" ")
    n,m = int(n),int(m)
    x = 0
    r = 0
    while r != n :
        r += 1
        b = list(input().split(" "))
        globals()["i"+f"{x+1}"] = list(map(int , b))
        #i1 = [1,2,3]
        #i2 = [5,3,1]
        x += 1
    
    l = []
    z = 1
    for i in i1:
        l.append((i,))
        # l = [(1,) , (2,) , (3,) ]
    while z != n :
        l.sort(key = lambda x:min(x))
        globals()["i"+f"{z+1}"].sort(reverse = True )
        k = 0
        for i in globals()["i"+f"{z+1}"] :
            l[k] += (i,)
            # l = [(1,5) , (2,3) , (3,1) ]
            k += 1
            
        z += 1

    p = 0
    for i in l[0] :
        for i in l:
            print(i[p] , end = " ")
        p += 1
        print()
        
        
       