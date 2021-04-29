#Status : Test Failed
#https://codeforces.com/contest/1514/problem/A

def fun(a,b,s):
    x = 0
    y = 0
    x += s.count("0")
    y += s.count("1")
    p = 0
    z = s.count("?")
    if x+y+z != a+b :
        return("-1")
    elif x+y+z == a+b :
        z = 0
        l = list(s)
        l2 = l.copy()
        l2.reverse()
        o = -1
        for i in l:
            o+=1
            if i=="1":
               if l2[o] == "0":
                   return -1
            if i=="0":
               if l2[o] == "1":
                   return -1
        for i in s :

            if i == "?" :
                if l2[z]!= "?" :
                    if l2[z]== "1":
                        l.pop(z)
                        l.insert(z,"1")
                        y +=1
                    elif l2[z] == "0" :
                        l.pop(z)
                        l.insert(z,"0")
                        x += 1
            z += 1
        if  len(l)==1:
            if x!=a and l[0]=="?":
                l=["0"]
            if y!=b and l[0]=="?":
                l = ["1"]

        while p <= len(l) :
            if  len(l)==1 :
                if  "1" in l and a==0 and b==1 :
                    return(l)
                elif "0" in l and b==0 and a==1:
                    return l
                    break
                else :
                    return (-1)
                    break
            if x== a and y == b:
                return(l)
                break
            if (a-x)%2 != 0 and x!=a and l[len(l)//2 + 1]=="?" and len(l)%2!=0:
                l.pop(len(l)//2 + 1)
                l.insert(len(l)//2 + 1 , "0")
                x += 1

            if x== a and y == b:
                return(l)
                break

            if (b-y)%2 != 0 and y!= b and l[len(l)//2 + 1]=="?" and len(l)%2!=0:
                l.pop(len(l)//2 + 1)
                l.insert(len(l)//2 + 1 , "1")
                y += 1
            if x== a and y == b:
                return(l)
                break

            if (a-x)%2 != 0 and x!=a and l[len(l)//2 + 1]=="?" and len(l)%2==0:
                return(-1)
                break

            if (b-y)%2 != 0 and y!=a and l[len(l)//2 + 1]=="?" and len(l)%2==0:
                return(-1)
                break

            if x%2 == 0 and x!=a:
                if "?" in l :
                    z = l.index("?")
                l.pop(z)
                l.insert(z,"0")
                l.reverse()
                l.pop(z)
                l.insert(z,"0")
                x += 2
                l.reverse()

            if x== a and y == b:
                return(l)
                break

            if y%2 == 0 and y!=b:
                if "?" in l :
                    z = l.index("?")
                l.pop(z)
                l.insert(z,"1")
                l.reverse()
                l.pop(z)
                l.insert(z,"1")
                y += 2
                l.reverse()

            if x== a and y == b:
                return(l)
                break
            p += 1
        else :
            return("-1")
n = int(input())
z = 0
while z< n:
    z+=1
    a,b = input().split(" ")
    a , b = int(a) , int(b)
    s = input()
    r = fun(a,b,s)
    x = ""
    l = []
    if type(r)==type(l):
        for i in r:
            x+=i
        print(x)
    else :
        print(r)
