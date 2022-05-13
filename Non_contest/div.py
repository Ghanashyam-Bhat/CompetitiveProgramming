def div(r):
    if r<1400:
        return 4
    elif r<1600:
        return 3
    elif r<1900:
        return 2
    else:
        return 1

trials = int(input())
for trial in range(trials):
    rating = int(input())
    x = div(rating)
    print(f"Division {x}")