class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join([i for i in s if i.isalpha() or i.isdigit()])
        n = len(s)
        for i in range(n//2):
            cur,opp = s[i],s[n-i-1]
            if cur.isalpha():
                try:
                    if cur.lower() != opp.lower():
                        return False
                except AttributeError:
                    return False
            else:
                if cur != opp:
                    return False
        return True
