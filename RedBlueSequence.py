#https://codeforces.com/problemset/problem/1469/B
Status : Not Solved
number_of_cases = int(input())
while number_of_cases!= 0 :
    number_of_cases -= 1
    print(maximum(r,R,b,B))
    
def maximum(r,R,b,B):
    from math import *
    R.reverse()
    x = 0
    l = []
    for i in R :
        if i <= 0 and x==0:
            l.append(R.index(i))
        else :
            x+= 1 
    for i in l:
        R.pop(i)
    R.reverse()
    B.reverse()
    x = 0
    l = []
    for i in B:
        if i <= 0 and x==0:
            l.append(B.index(i))
        else :
            x+= 1 
    for i in l:
        B.pop(i)
    B.reverse()
    z = []
    x = 0
    l = []
    for i in R :
        if i >= 0 and x==0:
            l.append(R.index(i))
            z.append(i)
        else :
            x+= 1 
    for i in l:
        R.pop(i)
    
    x = 0
    l = []
    for i in B :
        if i >= 0 and x==0:
            l.append(B.index(i))
            z.append(i)
        else :
            x+= 1 
    for i in l:
        B.pop(i)