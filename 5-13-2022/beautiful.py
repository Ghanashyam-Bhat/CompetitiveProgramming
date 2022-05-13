#from time import sleep
trials = int(input())
for trial in range(trials):
    l  = list(map(int,list(input().split())))
    c = set(range(l[0],l[1]+1)).intersection(set(range(l[2],l[3]+1)))
    #print(c)
    #sleep(0.1)
    if len(c):
        print(min(c))
    else:
        print(l[0]+l[2])
