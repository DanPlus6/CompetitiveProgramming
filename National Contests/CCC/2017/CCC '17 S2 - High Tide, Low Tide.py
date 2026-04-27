# CCC '17 S2 - High Tide, Low Tide
from sys import stdin
input = stdin.readline

# read inout
N = int(input())
arr = list(map(int,input().split()))

# sort the tide measurements
arr.sort()

# index of middle element
mid = N//2

# array to store output
res = []

# sequence starts at low tide and alternates: low, high, low, high, ...
# lows must be descending, highs must be ascending
# because problem states any high tide value is greater than any low tide value
# then after sorting we can assume the lower half = lows, upper half = highs

# however there are two cases:
# ODD case (sample: N=5, mid = 2, sorted: [1, 2, 3, 4, 5])
# mid+1 lows and mid highs (sequence ends on a low)
# lows: indices [0..mid]   --> [1, 2, 3]
# highs: indices [mid+1..N-1] --> [4, 5]
# start lows from the top of the low half (arr[mid]) and iterate left
# and start highs from the bottom of the high half (arr[mid+1]) and iterate right
# i=0: arr[2]=3 (low), arr[3]=4 (high)
# i=1: arr[1]=2 (low), arr[4]=5 (high)
# final low: arr[0]=1
# output: 3 4 2 5 1
if N%2:
    for i in range(mid):
        res.append(arr[mid-i])
        res.append(arr[mid+1+i])
    res.append(arr[0])

# EVEN case (sample: N=4, mid = 2, sorted: [1, 2, 3, 4])
# There are mid lows and mid highs (sequence ends on a high)
# lows: indices [0..mid-1]  --> [1, 2]
# highs: indices [mid..N-1] --> [3, 4]
# start lows from the top of the low half (arr[mid-1]) and iterate left
# and start highs from the bottom of the high half (arr[mid]) and iterate right
# i=0: arr[1]=2 (low), arr[2]=3 (high)
# i=1: arr[0]=1 (low), arr[3]=4 (high)
# output: 2 3 1 4
else:
    for i in range(mid):
        res.append(arr[mid-1-i])
        res.append(arr[mid+i])
    

# python automatically adds spacing between list items to save us trouble
# of having to check if we print a space or a new line of a value
print(*res)

