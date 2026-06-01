# 2144. Minimum Cost of Buying Candies With Discount

class Solution:
    def minimumCost(self, cost: list[int]) -> int:
        res = 0
        cost.sort(reverse=True)

        it = 0
        for _ in range(len(cost) // 3):
            first = cost[it]
            res += first
            it += 1

            second = cost[it]
            res += second
            it += 2
        
        for i in range(it, len(cost)):
            res += cost[i]

        return res
