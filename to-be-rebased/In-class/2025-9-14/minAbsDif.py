N,M = map(int, input().split())
A = sorted(set(list(map(int, input().split()))))
B = sorted(set(list(map(int, input().split()))))

difs = []
for i in A:
    for j in B:
        difs.append(abs(i-j))

print(min(difs))