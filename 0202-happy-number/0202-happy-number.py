class Solution:
    def isHappy(self, n: int) -> bool:
        def getNext(n: int) -> int:
            num = 0
            
            while n > 0:
                n, digit = divmod(n, 10)
                num += digit ** 2
            
            return num
        
        seen = set()
        seen.add(n)
        
        while True:
            tmp = getNext(n)
            if tmp == 1:
                return True

            if tmp in seen:
                return False
            
            seen.add(tmp)
            n = tmp
        
        