# optimized ver of below by caching last element (beats 100% yippee)
class Solution:
    def removeAnagrams(self, words: list[str]) -> list[str]:
        ret = [words[0]]

        last = words[0]
        for i in range(1,len(words)):
            cur = words[i]
            
            if sorted(cur) != sorted(last):
                ret.append(cur)
            last = cur
        
        return ret


# below's one-liner
"""
class Solution:
    def removeAnagrams(self, words: list[str]) -> list[str]:
        return [words[0]] + [words[i] for i in range(1,len(words)) if sorted(words[i]) != sorted(words[i-1])]
"""

# faster approach, instead of removing, use an array to keep the checked non-anagrams
"""
class Solution:
    def removeAnagrams(self, words: list[str]) -> list[str]:
        ret = [words[0]]

        for i in range(1,len(words)):
            cur = words[i]
            
            if sorted(cur) != sorted(words[i-1]):
                ret.append(cur)
        
        return ret
"""

# my solution
"""
class Solution:
    def removeAnagrams(self, words: list[str]) -> list[str]:
        def isAnagram(s: str, t: str) -> bool:
            if len(s) != len(t):
                return False
            t = list(t)
            
            for i in s:
                try:
                    t.remove(i)
                except ValueError:
                    return False
            
            return t == []
        
        i = 1
        while i < len(words):
            try:
                s,t = words[i-1],words[i]
                if isAnagram(s,t):
                    words.pop(i)
                else:
                    i += 1
            except IndexError:
                break
        
        return words
"""

print(Solution().removeAnagrams(["abba","baba","bbaa","cd","cd"]))
