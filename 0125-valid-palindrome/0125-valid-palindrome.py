class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.split(" ")
        s = "".join(s)
        i, j = 0, len(s) - 1

        while i < j:
            if s[i].isalnum() and s[j].isalnum():
                if s[i].lower() == s[j].lower():
                    i += 1
                    j -= 1
                    continue
                else:
                    return False
            if not s[i].isalnum():
                i += 1

            if not s[j].isalnum():
                j -= 1

        return True