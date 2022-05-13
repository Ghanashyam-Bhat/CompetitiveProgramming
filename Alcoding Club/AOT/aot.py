trials = int(input())
for trial in range(trials):
    n,m = input().split()
    n,m = int(n),int(m)
    nl = list(input().split())
    nl = list(map(int,nl))
    ml = list(input().split())
    ml = list(map(int,ml))
    nl.sort()
    ml.sort()
    d = 0
    while True:
        c = 0 ;l  =list();
        for i in range(n,0,-1):
            l.append(list(ml[i]))
        for i in range(n,m):
            if c<len(nl) and sum(l[c]) < nl[c] :
                l[c].append(ml[i])
            elif c<len(nl) :
                c +=1 
                l[c].append(ml[i])
            else :
                print("True")
                print(d)
        ml = ml[m-n-c : ]
        nl = nl [c : ]
        d += m-n-c
        m = m-n-c 
        n = n-c
    if n!=0 and m==0 :
        print("False")

    
"""
Sample Input
1
3 10
20 15 12
5 6 7 3 2 5 5 7 2 6
"""