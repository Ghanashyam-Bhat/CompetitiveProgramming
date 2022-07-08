# Find 3 numbers such that their XOR operation results in the given number (Use binary form)

trials = int(input())
for trial in range(trials):
    n = int(input())
    s = list(bin(n)[2:])
    if s.count('1')<2:
        print(-1)
    t = 0
    k = 0
    for i in range(len(s)):
        if i == 1 and k ==0:
            k =1
            print(2**i,end=" ")
        elif i==1:
            t += 2**i
    print(t,end= " ")
    print(0)
