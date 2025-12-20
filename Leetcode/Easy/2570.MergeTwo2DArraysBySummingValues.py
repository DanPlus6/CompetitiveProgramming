class Solution:
    def mergeArrays(self, nums1: list[list[int]], nums2: list[list[int]]) -> list[list[int]]:
        subt = {}
        for i in nums1:
            subt.update({i[0]:i[1]})

        for i in nums2:
            if i[0] in subt.keys():
                subt.update({ i[0]:(subt[i[0]]+i[1]) })
            else:
                subt.update({i[0]:i[1]})
        
        return [[k,v] for k,v in sorted(subt.items())]
        
