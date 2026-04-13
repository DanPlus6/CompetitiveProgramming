# CCCHK '08 J3 - Phone book
def main():
    pb = {}
    N = int(input())
    for i in range(N):
        a = input().split()
        pb[int(a[1])] = a[0]
    if N == 1:
       for k,v in pb.items():
           return v

    D = int(input())
    dials = [int(input()) for i in range(D)]
    dials.sort()

    last,left,most,ct = dials[0],0,dials[0],0
    for i in range(1,D):
        cur = dials[i]
        if cur != last:
            seg = (i-1-left)
            if seg > ct:
                ct = seg
                most = dials[i-1]
            last = cur
            left = i
    return pb[most]

print(main())
