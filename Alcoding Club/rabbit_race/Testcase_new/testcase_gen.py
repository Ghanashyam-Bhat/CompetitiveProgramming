import random as r
trials = r.randint(1,500)
print(trials)
for trial in range(trials) :
    op = r.randint(1,1000)%3
    m =  r.randint(1,100)
    n =  r.randint(1,m)
    print(m,n)
    
    if op==0:
        for i in range(n):
            z = r.randint(0,1000)
            if z%2==0:
                print(r.randint(0,30),end= " ")
            else:
                print(0,end= " ")
        print()
        for i in range(n):
            print(r.randint(0,m),end= " ")
        print()
    elif op==1 :
        for i in range(n):
            print(r.randint(0,30),end= " ")
        print()
        for i in range(n):
            z = r.randint(0,1000)
            if z%2 == 0:
                print(0,end= " ")
            else:
                print(r.randint(0,(2*m)%n),end= " ")
        print()
    else:
        l = [0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,3,4,5]
        k = r.randint(0,1000)
        if k%2==0:
            for i in range(n):
                print(r.randint(0,30),end= " ")
            print()
            for i in range(n):
                z = r.randint(0,1000)
                if z%5 != 0:
                    print(r.choice(l),end= " ")
                else:
                    print(r.randint(0,(2*m)%n),end= " ")
            print()
        else:
            for i in range(n):
                z = r.randint(0,1000)
                if z%5!=0:
                    print(r.randint(0,30),end= " ")
                else:
                    print(r.choice(l),end= " ")
            print()
            for i in range(n):
                print(r.randint(0,(2*m)%n),end= " ")
            print()