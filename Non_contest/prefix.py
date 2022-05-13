trials = int(input())
for trial in range(trials):
    s = input()
    for i in range(len(s)):
        x = list(set(s[i+1:]))
        if s[i] not in x:
            print(s[i:])
            break
