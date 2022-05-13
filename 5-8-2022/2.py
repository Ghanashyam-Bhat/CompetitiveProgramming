trials = int(input())
import math
for trial in range(trials):
    length = int(input())
    l = list(map(int,list(input().split())))
    prev = l[-1]
    x = 0
    for i in range(length-2,-1,-1):
        if prev==0:
            x = -1
            break 
        while l[i]>= prev:
            #print(l[i],prev)
            x +=1
            l[i] //= 2
        prev = l[i]

    print(x)