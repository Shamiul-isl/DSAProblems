class Solution:
    def isValid(self, s: str) -> bool:
        opening = []
        for cur in s:
            if cur == "(" or cur == "{" or cur == "[":
                opening.append(cur)
            elif len(opening) > 0: 
                if (cur == ")" and opening[-1] == "(") or (cur == "]" and opening[-1] == "[") or (cur == "}" and opening[-1] == "{"):
                    opening.pop()
                else:
                    return False    
            else:
                return False
        
        if len(opening) > 0:
            return False
        return True