def test(l,d,e):
    for i in range(len(l)):
        for j in range(len(l)):
            #print(l[i],l[j])
            if (i!=j) and (l[i]+l[j])<=d:
                c = l.copy()
                c.remove(l[i])
                c.remove(l[j])
                if(c[0]<=e):
                    return 1;
    return 0;

trials = int(input())
for trial in range(trials):
    a,b,c,d,e = input().split()
    a,b,c,d,e = int(a),int(b),int(c),int(d),int(e)
    l=[a,b,c]
    #print(l)
    v = test(l,d,e)
    if v==1:
        print("YES")
    elif v==0:
        print("NO")