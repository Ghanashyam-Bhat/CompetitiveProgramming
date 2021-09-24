#https://codeforces.com/problemset/problem/1569/B
trials = int(input())
for trial in range(trials):
    n = int(input())
    c = 0
    arr = []
    wins = []
    for i in range(n):
        wins.append([])
        arr.append([0]*n)
    exp = input()
    for i in range(n):
        for j in range(n):
            if i==j :
                arr[i][j] = 'X'
            elif exp[i]== '2' and exp[j]=='2' and arr[i][j] == 0 and wins[i].count('+')<1 and wins[j].count('-') < n :
                arr[i][j] = '+'
                arr[j][i] = '-'
                c += 1
                wins[i].append('+')
                wins[j].append('-')
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 0:
                arr[i][j] = '='
    if(c == exp.count('2')):
        print("YES")
        for i in range(n):
            for j in range(n):
                print(arr[i][j],end="")
            print()
    else :
        print("NO")
                
