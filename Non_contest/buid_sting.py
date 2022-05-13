trials = int(input())
for trial in range(trials):
    s = input()
    if ('aba' in s) or ('bab' in s):
        print("NO")
    else:
        if len(s)==1:
            print("NO")
        elif s[0]!=s[1] or s[-1]!=s[-2]:
            print("NO")
        else:
            print("YES")