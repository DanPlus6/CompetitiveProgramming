# Another Sorting
from sys import stdin,stdout
N = int(stdin.readline())
M = {'0':[],'1':[],'2':[],'3':[],'4':[],'5':[],'6':[],'7':[],'8':[],'9':[]}
for i in stdin.readline().split():
    M[i[-1]].append(i)

for i in range(10):
    M[str(i)].sort(reverse=True,key=int)

end = 0
for i in range(9,-1,-1):
    if M[str(i)]:
        end = i
        break

for i in range(end):
    if not M[str(i)]: continue
    stdout.write(' '.join(M[str(i)])+' ')

stdout.write(' '.join(M[str(end)]))

