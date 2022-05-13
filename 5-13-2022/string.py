#https://codeforces.com/contest/1680/problem/C

trials = int(input())
for trial in range(trials):
    s = list(map(int,list(input())))
    if len(s)==s.count(1):
        print(0)
    else:
        li = []
        ones = 0
        z = s.count(0)
        zr = z
        for i in range(len(s)):
            if s[i]==1:
                ones+=1
            else:
                li.append([i,ones,0])
                ones = 0
        li.reverse()
        s.reverse()
        ones = 0

        j = 0
        for i in range(len(s)):
            if s[i]==1:
                ones+=1
            else:
                li[j][2] = ones 
                ones = 0
                j+=1
        rli = li
        mi  = z
        mir = z
        li.reverse()
        s.reverse()
        o = 0
        ro = 0
        tm = 0
        print(li)
        checkpoint1 = 0
        ch = []

        
        for i in range(len(li)):
            o += li[i][1]
            z -= 1
            tm = max(o,z)
            if tm<mi:
                checkpoint1 = i
                mi = tm 
                ch.append((mi,checkpoint1))

        tm = 0
        checkpoint2 = 0
        chr = []
        for i in range(len(rli)):
            ro += rli[i][2]
            zr -= 1
            tm = max(ro,zr)
            if tm<mir:
                checkpoint2 = len(li) - i
                mir = tm 
                chr.append((mir,checkpoint2))

        chr.reverse()
        f = -1
        r = -1
        if checkpoint1<checkpoint2:
            print(max(mi,mir)-min(mi,mir))
        else:
            m_check = 0
            for i in range(min(len(ch),len(chr))):
                temp = abs((chr[i][0]-mir)-(ch[i][0]-mi))
                if temp>m_check:
                    m_check = temp
                    if (chr[i][0]-mir)-(ch[i][0]-mi)>0:
                        r = i
                        f = i-1
            
            if r!=-1 and f!=-1: 
                print(max(chr[r][0],ch[f][0])-min(chr[r][0],ch[f][0]))
            else:
                if r==-1:
                    print(ch[f][0])
                else:
                    print(chr[r][0])