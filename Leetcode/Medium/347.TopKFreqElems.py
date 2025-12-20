# my O(n) O(n) attempt
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        count = {}
        for i in nums:
            if i not in count:
                count[i] = 1
            else:
                count[i] += 1

        return [i[0] for i in sorted(count.items(),key = lambda x: x[1],reverse=True)][:k]
