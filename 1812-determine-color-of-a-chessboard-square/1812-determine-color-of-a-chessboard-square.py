class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        one, two = coordinates[0], coordinates[1]
        
        if ord(one) % 2 == 0:
            if int(two) % 2 == 0:
                return False
            return True
        else:
            if int(two) % 2 == 0:
                return True
            return False