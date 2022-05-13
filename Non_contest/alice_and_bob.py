trials = int(input())
for trial in range(trials):
    s = input()
    t = 0
    x = 0
    if len(s)>1:
        if len(s)%2 ==0:
            for i in range(len(s)):
                t += (ord(s[i])-ord('a')+1)
            x = 0
        else:
            if s[0]>s[-1]:
                for i in range(0,len(s)-1):
                    t += (ord(s[i])-ord('a')+1)
                x = (ord(s[-1])-ord('a')+1)
            else:
                for i in range(1,len(s)):
                    t += (ord(s[i])-ord('a')+1)
                x = (ord(s[0])-ord('a')+1)
        print(f"Alice {t-x}")
    else:
        print(f"Bob {ord(s[0])-ord('a')+1}")