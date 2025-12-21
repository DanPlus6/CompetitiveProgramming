# CCC '15 J4 - Wait Time
from sys import stdin

def main() -> str:
    M = int(stdin.readline())
    time,hold = 0,0
    recv = {}
    seen = set()
    res = {}
    for i in range(M):
        msg,friend = stdin.readline().split()
        if msg == 'W':
            hold = int(friend)-1
        elif msg == 'R':
            recv[friend] = time
            seen.add(friend)
        else:
            if friend not in res.keys():
                res[friend] = time - recv[friend]
                seen.remove(friend)
            else:
                res[friend] += time - recv[friend]
                seen.remove(friend)
        if not hold:
            time += 1
        else:
            time += hold
            hold = 0

    if seen:
        for i in seen:
            res[i] = -1
    
    # for k,v in res.items():
    #     print(k,v)
    for i in sorted([(k,v) for k,v in res.items()]):
        print(i[0],i[1])
    

"""
def main() -> str:
    M = int(stdin.readline())
    time = 0
    out = {}
    times = {}
    for i in range(M):
        msg,friend = stdin.readline().split()
        if msg == 'W':
            time += (int(friend)-1)
            continue
        if msg == 'R' and friend not in times.keys():
            times[friend] = time+1
        elif msg == 'S':
            if friend in out:
                out[friend] += (time-times[friend])
            else:
                out[friend] = (time-times[friend])
        time += 1
    for k,v in out.items():
        if v == 0:
            print(k,-1)
            continue
        print(k,v)
"""


main()
