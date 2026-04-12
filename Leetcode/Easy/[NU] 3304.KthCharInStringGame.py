# Other person's solution (what the actual heck) (hold on wait this is actually 🧠🧠🧠)
"""
class Solution:
    def kthCharacter(self, k: int) -> str:
        sb = ['a']
        while len(sb) < k:
            size = len(sb)
            for i in range(size):
                next_char = chr(ord('a') + ((ord(sb[i]) - ord('a') + 1) % 26))
                sb.append(next_char)
        return sb[k - 1]

"""

# Another person's solution (bitwise approach) (I have yet to understand this)
# david it is time to study Computer **SCIENCE**
# david it is time to get low level
# david, "One cannot expect to reap if one cannot be expected to sow"
class Solution:
        def kthCharacter(self, k: int) -> str:
            return chr(ord('a') + (k - 1).bit_count())


# My solution (inefficient👎, space complexity🤮)
"""
class Solution:
    def kthCharacter(self, k: int) -> str:
        word = 'a'
        alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
        while len(word) < k:
            lclWord = word
            for i in lclWord:
                next = alphabet.index(i)+1
                if next > 25:
                    word+='a'
                word+=alphabet[alphabet.index(i)+1]
                
        return word[k-1]
        # return word
            
"""

# For testing (I hav eyet to understand the bitwise solution):

# from time import sleep as wait
# k = int(input("K: "))
# word = Solution.kthCharacter(None,k)
# for i in range(len(word)):
#     if i+1 == len(word)/2:
#         print('---------------------------------------------------')
#     wait(0.08)
#     currentChar = word[i]
#     print(currentChar,'|','Ord: '+str(ord(currentChar)),'|',str(bin(ord(currentChar)))[2:])
    
# print('---------------------------------------------------\n',
#     k,'|','Bin(k-1) =',bin(k-1),'\n')
# halfLen = len(word)//2
# print("'"+word[:halfLen]+'|'+word[halfLen:]+"'")
