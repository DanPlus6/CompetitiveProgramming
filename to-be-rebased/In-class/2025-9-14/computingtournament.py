# sir Bruce's help
N,K = map(int, input().split())

participants = []
for i in range(N):
    p = list(map(int, input().split()))
    participants.append((p[0],p[1],i+1))
participants.sort()

participants = participants[(0-K):]
Max = 0
Ind = 0
for i in range(K):
    if participants[i][1] > Max:
        Max = participants[i][1]
        Ind = participants[i][2]

print(Ind)


# my version used (buggy asl)
"""
N,K = map(int, input().split())

r1, r2 = [],[]
for i in range(N):
    participant = list(map(int, input().split()))
    r1.append(participant[0])
    r2.append(participant[1])


Max = float('-inf')
MaxInd = []
for i in range(N):
    if r1[i] > Max:
        Max = r1[i]
        MaxInd.append(i)
tmp = []
for i in MaxInd[-K:]:
    tmp.append(r2[i])

Max = float('-inf')
MaxInd = 0
for i in range(K):
    if tmp[i] > Max:
        Max = tmp[i]
        MaxInd = i

print(MaxInd)
"""
