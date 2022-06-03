def decimalToBinary(n):
    return bin(n).replace("0b", "")

trials = int(input())
for trial in range(trials):
    x = int(input())
    s = decimalToBinary(x)
    s = list(s)
    s.reverse()
    t1 = 0
    t2 = 0
    p = 0
    for i in range(len(s)):
        if t1==0 and s[i]=='1':
            p += 2**(i)
            t1 = 1
        elif t1!=0 and t2==0 and ('1' in s[i:]):
            t2 = 1
        elif t1!=0 and t2!=0:
            break;
    else:
        for i in range(len(s)):
            if t2==0 and s[i] == '0':
                p += 2**(i)
                t2 = 1
        if t2==0 or t1==0:
            p+= 2**(len(s))
    print(p)