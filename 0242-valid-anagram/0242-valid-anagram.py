class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        seen = {}
        
        for c in s:
            if c in seen:
                seen[c] = seen[c] + 1
            else:
                seen[c] = 1
        
        for c in t:
            if c not in seen:
                return False
            
            if seen[c] == 1:
                seen.pop(c)
            else:
                seen[c] = seen[c] - 1
        
        if seen != {}:
            return False
        return True
        