S = input()
n = len(S)
if n == 2:
    print(2)
    exit()

left = 0
Max = 0
for i in range(n):
    if S[i] == 'A':
        left = i
        break

for i in range(left,n):
    if S[i] == 'Z':
        Max = i-left+1

print(Max)
