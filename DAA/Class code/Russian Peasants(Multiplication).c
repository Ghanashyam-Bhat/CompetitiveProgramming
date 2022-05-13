def mul(n,m,x=0):
    if n==1:
        return m+x
    elif n%2==0:
        n >>=1 #div by 2 using right shift
        m <<=1 #mul by 2 using left shift
    else:
        n -= 1
        n >>=1
        x += m
        m <<=1
    return mul(n,m,x)
    
print(mul(5,8))