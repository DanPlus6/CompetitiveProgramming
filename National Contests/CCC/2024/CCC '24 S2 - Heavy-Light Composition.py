# CCC '24 S2 - Heavy-Light Composition
T,N = map(int,input().split())

for i in range(T):
    line = input()
    seen = set()
    heavy = set()

    for j in range(N):
        char = line[j]
        if char not in seen:
            seen.add(char)
        else:
            heavy.add(char)

    lastSeen = True if line[0] in heavy else False

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


