class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = set(['a', 'e', 'i', 'o', 'u'])
        
        i = 0
        j = len(s) - 1
        
        
        while i < j:
            if s[j].lower() in vowels and s[i].lower() in vowels:
                tmp = s[i]
                s = s[:i] + s[j] + s[i+1:j] + s[i] + s[j+1:]
                # s[j] = tmp
                i += 1
                j -= 1
                continue

            if s[j].lower() not in vowels:
                j -= 1

            if s[i].lower() not in vowels:
                i += 1
        return s