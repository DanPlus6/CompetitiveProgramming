# DMOPC '19 Contest 5 P1 - Conspicuous Cryptic Checklist
N,M = map(int,input().split())
items = [input() for i in range(N)]
assignments = sorted([[Ti:=int(input()),list(set([input() for j in range(Ti)]))] for i in range(M)])

asms = 0
for i in assignments:
    for j in range(len(i[1])):
        if i[1][j] not in items:
            break
    else:
        asms += 1

print(asms)

