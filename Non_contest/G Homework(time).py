#https://codeforces.com/problemset/problem/1574/B

def m_zero(a,b,c):
    if b+c >= a-1 and a+c >= b-1 and a+b>= c-1 :
        print("YES")
    else:
        print("NO")
      
def m_non_zero(a,b,c,m):
    l = [a,b,c]
    while(m):
        l.sort(reverse=True)
        if l[0] <2:
            print("NO")
            m = -1
            break;
        l[0] -= 1
        m -= 1
    if m==0:
        m_zero(l[0],l[1],l[2])

trials = int(input())
for trial in range(trials):
    a,b,c,m = input().split()
    if(int(m)==0):
        m_zero(int(a),int(b),int(c))
    else:
        m_non_zero(int(a),int(b),int(c),int(m))