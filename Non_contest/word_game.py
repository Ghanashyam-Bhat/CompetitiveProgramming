#from time import sleep
trials = int(input())
for trial in range(trials):
    s,t = input().split()
    s = list(s)
    x = len(s)
    check  = 0
    for i in range(len(t)-1,-1,-1):
        #print(t[i])
        #sleep(0.2)
        if (t[i] in s[x:]) and (t[i] not in t[i+1:]):
            print("NO")
            break
        elif (t[i] in s[x:]) and (t[i] in t[i+1:]) and (s[x:].count(t[i])!= t[i+1:].count(t[i])):
            print("NO")
            break
        elif t[i] in s[:x]:
            temp = s[:x]
            temp.reverse()
            x =  (temp.index(t[i])+len(s)-x)
            #print(x)
            x = len(s)-x
            if x==1:
                check+=1
            #s.pop(x)
            #print(x)
            #print(i)
        else:
            print("NO")
            break
        if check>1:
            print("NO")
            break
    else:
        print("YES")