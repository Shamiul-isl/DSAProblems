class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x # return x if it is 0 or 1

        left, right = 2, x // 2 
        mid = 0
        num = 0 
        while left <= right: # binary search for the square root
            # you use left + (right - left) / 2 to avoid overflow issues if right and left are               big numbers
            mid = left + (right - left) // 2 # find the middle element
            num = mid * mid
            if num > x:
                right = mid - 1 # if mid * mid is greater than x, set right to mid - 1
            elif num < x:
                left = mid + 1 # if mid * mid is less than x, set left to mid + 1
            else:
                return mid # if mid * mid is equal to x, return mid
        return right