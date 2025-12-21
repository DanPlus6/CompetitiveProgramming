# CCC '24 S2 - Heavy-Light Composition
T,N = map(int,input().split())
letters = [input() for i in range(T)]

for i in range(T):
    line = letters[i]
    seen = []
    heavy = []

    for j in range(N):
        char = line[j]
        if char not in seen:
            seen.append(char)
        else:
            heavy.append(char)
    
    if line[0] in heavy:
        lastSeen = True
    else:
        lastSeen = False

    for j in range(1,N):
        if line[j] in heavy:
            if lastSeen:
                print("F")
                break
            lastSeen = True
        else:
            if not lastSeen:
                print("F")
                break
            lastSeen = False
    else:
        print("T")


