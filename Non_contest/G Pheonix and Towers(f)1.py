cases = int(input())
while cases != 0 :
    cases -= 1
    l = list(input().split(" "))
    l = list(map(lambda x:int(x),l))
    n = l[0]
    m = l[1]
    x = l[2]
    h = list(input().split(" "))
    hi = h.copy()
    h = list(map(lambda x:int(x),h))
    h.sort(reverse=True)
    avg = sum(h)/m
    ma = avg + x/2
    mi = avg - x/2
    z = n//m
    #print(z)
    a = 0
    for i in range(z):
        #print("*")
        globals()[f"a{i+1}"] = []
        for j in range(m):
            globals()[f"a{i+1}"].append(h[j])
        a += 1
        h = h[m:]
        #print(globals()[f"a{a+1}"])
    e = []
    v = []
    for i in range(a-1):
        e.append(f"a{i+1}")
    for i in range(m):
        globals()[f"m{i+1}"] = []
        v.append(f"m{i+1}")
        for j in e:
            r = globals()[j]
            globals()[f"m{i+1}"].append(r[i])
    #print(v,e)
    #for i in e:
    #    print(globals()[i])