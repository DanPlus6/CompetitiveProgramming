# 1331. Rank Transform of An Array
class Solution:
    def arrayRankTransform(self, arr: list[int]) -> list[int]:
        if not arr: return []
        
        unique = set(arr)
        if len(unique) == 1: return [1]*len(arr)

        ranks = {}
        unique = sorted(unique)
        for i in range(len(unique)):
            ranks[unique[i]] = i+1
        
        for i in range(len(arr)):
            arr[i] = ranks[arr[i]]
        return arr


# print(Solution.arrayRankTransform(None,[37,12,28,9,100,56,80,5,12]))
