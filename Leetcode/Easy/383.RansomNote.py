# more efficient solution
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        
        for i in ransomNote:
            if i not in magazine:
                return False
            else:
                magazine = magazine.replace(i,"",1)

        return True

# original solution
"""
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        
        from collections import Counter
        ransomNote = Counter(ransomNote)
        magazine = Counter(magazine)

        for k,v in ransomNote.items():
            if ransomNote[k] > magazine[k]:
                return False
        
        return True
"""
        

        