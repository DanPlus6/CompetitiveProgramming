# 2657. Find the Prefix Common Array of Two Arrays

class Solution:
    def findThePrefixCommonArray(self, A: list[int], B: list[int]) -> list[int]:
        PCA = [0]*len(A)
        freq = [0]*(len(A)+1)

        freq[A[0]] += 1
        freq[B[0]] += 1
        if freq[B[0]] == 2: 
            PCA[0] += 1

        for i in range(1,len(A)):
            PCA[i] = PCA[i-1]

            freq[A[i]] += 1
            if freq[A[i]] == 2: PCA[i] += 1
            
            freq[B[i]] += 1
            if freq[B[i]] == 2: PCA[i] += 1
        

        return PCA

