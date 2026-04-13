# SAC '22 Code Challenge 5 Junior P3 - Media List
N,Q = map(int, input().split())
medList = {}
res = []
for i in range(Q):
    header,eye,name = input().split()
    if header == '2':
        if eye not in medList:
            medList[eye] = {name}
        else:
            medList[eye].add(name)
    else:
        try:
            res.append(1) if name in medList[eye] else res.append(0)
        except KeyError:
            res.append(0)

for i in res:
    print(i)
