def test(l,d,e):
    if min(l)>e or sum(l)>(d+e) :
        return 0
    else :
        for i in range(len(l)):
            if l[i]<=e:
                c = l.copy()
                c.pop(i)
                if sum(c)<=d :
                    return 1
    return 0

trials = int(input())
for trial in range(trials):
    a,b,c,d,e = input().split()
    a,b,c,d,e = int(a),int(b),int(c),int(d),int(e)
    l=[a,b,c]
    l.sort(reverse=True)
    v = test(l,d,e)
    if v==1:
        print("YES")
    elif v==0:
        print("NO")