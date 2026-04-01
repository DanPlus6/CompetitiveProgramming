# CCC '24 J3 - Bronze Count
N = int(input())
scores = [int(input()) for i in range(N)]
scores.sort(reverse=True)

encountered = []
placement = 0
p = 0
for i in range(N):
    cur = scores[i]
    if cur not in encountered:
        encountered.append(cur)
        placement += 1
    if placement == 3 and cur in encountered:
        p+=1

print(encountered[2],p)


        
