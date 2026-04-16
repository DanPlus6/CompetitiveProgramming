# Permutations
class Solution:
    def permuteUnique(self, nums: list[int]) -> list[list[int]]:
        N = len(nums)
        if N == 1: return [nums]
        MAPPER = {}
        for i in range(N): MAPPER[i] = nums[i]

        res = set()
        path = []
        plen = 0

        def main():
            nonlocal plen
            if plen == N:
                res.add(tuple([MAPPER[i] for i in path]))
                return  
            for i in range(N):
                if i not in path:
                    path.append(i)
                    plen += 1

                    main()

                    path.pop()
                    plen -= 1

        main()
        return [list(i) for i in res]
